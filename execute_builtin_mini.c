/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin_mini.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:12:42 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:12:43 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_builtin(t_d *data, t_ex *exec, pid_t *pids)
{
	if (ft_strcmp(data->exec->cmd[0], "env") == 0)
		ft_env(data, exec->cmd);
	else if (ft_strcmp(data->exec->cmd[0], "pwd") == 0)
		ft_pwd(data);
	else if (ft_strcmp(data->exec->cmd[0], "export") == 0)
		ft_export(data, exec->cmd);
	else if (ft_strcmp(data->exec->cmd[0], "unset") == 0)
		ft_buitin(data, exec->cmd);
	else if (ft_strcmp(data->exec->cmd[0], "exit") == 0)
		ft_exit(data, pids, exec->cmd);
	else if (ft_strcmp(data->exec->cmd[0], "echo") == 0)
		ft_echo(data, exec->cmd);
	else if (ft_strcmp(data->exec->cmd[0], "cd") == 0)
		builtin_cd(data, exec->cmd);
}
