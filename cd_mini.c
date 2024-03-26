/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_mini.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:01:06 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:01:07 by frukundo         ###   ########.fr       */
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
