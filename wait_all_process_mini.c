/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all_process_mini.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:22:14 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:22:15 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_waiting(t_d *data, pid_t *pids, int flag)
{
	int	i;

	i = -1;
	if (flag == 1)
	{
		waitpid(pids[++i], &data->exstatus, 0);
		if (WEXITSTATUS(data->exstatus))
			data->exstatus = WEXITSTATUS(data->exstatus);
	}
	else
	{
		while (++i < data->proc_nb)
			waitpid(pids[i], &data->exstatus, 0);
		if (WEXITSTATUS(data->exstatus))
			data->exstatus = WEXITSTATUS(data->exstatus);
	}
}
