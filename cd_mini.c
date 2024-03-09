/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_mini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:11:36 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:11:37 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_cd(t_d *data, char **arg)
{
	int			len;
	struct stat	file_info;

	len = array_size(arg);
	if (len > 2)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		data->exstatus = 1;
		return ;
	}
	else if (len == 1)
		chdir(data->line0);
	else if (len == 2)
	{
		if (stat(arg[1], &file_info) != 0)
		{
			ft_printf_fd(2, "cd: %s: No such file or directory\n", arg[1]);
			data->exstatus = 1;
			return ;
		}
		chdir(arg[1]);
	}
	data->exstatus = 0;
}
