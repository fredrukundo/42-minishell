/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_and_builtin_mini.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:16:22 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:23:03 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_ex	*cmds_to_arr(int *lx, t_list *token, int len, int size);
static char	*stringcpy(t_list *token);
static void	start_exec(t_ex *exec, int lx, int size);

void	cmd_args_getter(t_list *token, int *lexer, t_d *data)
{
	t_list	*temp;
	int		len;
	int		redirect;

	len = 0;
	redirect = 0;
	temp = token;
	while (temp != NULL && lexer[len] != PIPE)
	{
		if (lexer[len] == CMD)
			data->is_cmd = 1;
		else if (lexer[len] == BUILTIN)
			data->is_builtin = 1;
		else if (is_redirect(lexer[len]) == 1)
		{
			temp = temp->next;
			len++;
			redirect += 2;
		}
		temp = temp->next;
		len++;
	}
	if (data->is_cmd == 1 || data->is_builtin == 1)
		data->exec = cmds_to_arr(lexer, token, len, len - redirect);
}

static t_ex	*cmds_to_arr(int *lx, t_list *token, int len, int size)
{
	int		i;
	int		j;
	t_ex	*exec;

	exec = ft_calloc(sizeof(t_ex), 1);
	start_exec(exec, lx[0], size);
	i = -1;
	j = 0;
	while (++i < len)
	{
		if (is_redirect(lx[i]) == 0)
		{
			if (lx[i] == CMD || lx[i] == BUILTIN)
				exec->lx = lx[i];
			exec->cmd[j++] = stringcpy(token);
		}
		else
		{
			i++;
			token = token->next;
		}
		token = token->next;
	}
	exec->cmd[j] = NULL;
	return (exec);
}

static void	start_exec(t_ex *exec, int lx, int size)
{
	exec->lx = lx;
	exec->in = -2;
	exec->out = -2;
	exec->cmd = ft_calloc(sizeof(char *), size + 1);
}

static char	*stringcpy(t_list *token)
{
	char	*cmd;

	cmd = ft_calloc(sizeof(char), ft_strlen(token->content) + 1);
	ft_strlcpy(cmd, token->content, ft_strlen(token->content) + 1);
	return (cmd);
}
