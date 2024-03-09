/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all_process_mini.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:17:30 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:17:31 by hel-haia         ###   ########.fr       */
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
