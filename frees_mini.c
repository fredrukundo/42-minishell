/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:13:41 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:13:42 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_0(char **path, char **env, t_d *data, pid_t *pids)
{
	free(pids);
	ft_free_str_arr(&path);
	ft_free_str_arr(&env);
	free_2(data->exec);
	free_all(data);
}

void	free_1(t_d *data, pid_t *pids)
{
	free(pids);
	free_2(data->exec);
	free_all(data);
}

void	free_all(t_d	*data)
{
	rl_clear_history();
	if (data->env != NULL)
		lst_free(data->env);
	if (data->line != NULL)
		free(data->line);
	if (data->herdc != NULL)
		free(data->herdc);
	if (data->token != NULL)
		lst_free(data->token);
	if (data->lexer != NULL)
		free(data->lexer);
	if (data->line0 != NULL)
		free(data->line0);
	if (data != NULL)
		free(data);
}

void	lst_free(t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp != NULL)
	{
		list = list->next;
		if (temp->content)
			free(temp->content);
		free(temp);
		temp = list;
	}
}

void	free_2(t_ex *exec)
{
	t_ex	*temp;

	temp = exec;
	if (temp->cmd)
		ft_free_str_arr(&temp->cmd);
	free(exec);
}
