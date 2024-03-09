/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:12:47 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:12:48 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_d *data, pid_t *pids, char **arg)
{
	long	num;

	num = 0;
	if (data->exstatus != 0)
		num = data->exstatus;
	if (array_size(arg) > 2)
	{
		ft_printf_fd(2, "exit: too many arguments\n");
		free_1(data, pids);
		exit(2);
	}
	if (array_size(arg) == 2)
	{
		if (ft_strdigit(arg[1]) == 0)
		{
			ft_printf_fd(2, "exit: numeric argument required\n");
			free_1(data, pids);
			exit(2);
		}
		if (arg[1])
			num = ft_atol(arg[1]);
	}
	free_1(data, pids);
	exit(num);
}
