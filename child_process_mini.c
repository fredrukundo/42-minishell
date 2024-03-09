/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process_mini.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:12:11 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:12:12 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_children(t_d *data, t_list *token, int *lexer, pid_t *pids)
{
	int			fd[2];
	int			result;

	result = check_files(token, lexer, &fd[0], &fd[1]);
	if (result == 1)
	{
		cmd_args_getter(token, lexer, data);
		handle_pipes(data);
		if (fd[0] != -2 || fd[1] != -2)
			redirect_files(fd[0], fd[1]);
		if (data->is_builtin == 1 || data->is_cmd == 1)
			excecuting(data, fd, pids);
	}
	else if (result == 2 || result == 4)
		data->exstatus = 1;
	else if (result == 3)
		data->exstatus = 126;
	files_closing(fd[0], fd[1]);
	free(pids);
	free_all(data);
	exit(1);
}
