/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:12:36 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:12:37 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	forking(t_arg *arg, t_d *data);
static void	builting_execution(t_d *data);
static void	child_execution(t_d *data, t_arg *arg);
static void	child_execution_1(t_d *data, t_list *temp, int *lx, pid_t *pids);

void	execute(t_d *data)
{
	t_arg	arg;

	data->arg = &arg;
	arg.ix = 0;
	pipe(arg.fd1);
	pipe(arg.fd2);
	forking(&arg, data);
	closing_pipes(&arg);
}

static void	forking(t_arg *arg, t_d *data)
{
	data->is_cmd = 0;
	data->is_builtin = 0;
	if (data->proc_nb == 1 && data->built_chck == 1)
		builting_execution(data);
	else
		child_execution(data, arg);
}

static void	builting_execution(t_d *data)
{
	int	fd[2];
	int	result;
	int	backup[2];

	backup[0] = dup(0);
	backup[1] = dup(1);
	result = check_files(data->token, data->lexer, &fd[0], &fd[1]);
	if (result == 1)
	{
		cmd_args_getter(data->token, data->lexer, data);
		if (fd[0] != -2 || fd[1] != -2)
			redirect_files(fd[0], fd[1]);
		execute_builtin(data, data->exec, NULL);
		free_2(data->exec);
	}
	else if (result == 2 || result == 4)
		data->exstatus = 1;
	else if (result == 3)
		data->exstatus = 126;
	dup2(backup[0], 0);
	dup2(backup[1], 1);
	files_closing(fd[0], fd[1]);
}

static void	child_execution(t_d *data, t_arg *arg)
{
	pid_t	*pids;
	int		i;
	t_list	*temp;

	i = 0;
	temp = data->token;
	pids = ft_calloc(sizeof(int), data->proc_nb);
	while (arg->ix < data->proc_nb)
	{
		if (data->lexer[i] == PIPE)
		{
			i++;
			temp = temp->next;
		}
		pids[data->arg->ix] = fork();
		child_execution_1(data, temp, &data->lexer[i], pids);
		while (temp != NULL && data->lexer[i] != PIPE)
		{
			temp = temp->next;
			i++;
		}
		arg->ix++;
	}
	process_waiting(data, pids, data->proc_nb);
	free(pids);
}

static void	child_execution_1(t_d *data, t_list *temp, int *lx, pid_t *pids)
{
	sig_default();
	if (pids[data->arg->ix] == 0)
	{
		process_children(data, temp, lx, pids);
	}
	else
		sig_ignore();
	piping(data->arg);
}
