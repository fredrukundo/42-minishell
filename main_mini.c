/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:16:43 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:44:49 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_d	*data;

	(void)argv;
	if (argc == 1)
	{
		data = ft_calloc(1, sizeof(t_d));
		env_cpy(&data->env, envp, data);
		g_sig = &data->exstatus;
		readline_set(data);
		free_all(data);
	}
	return (0);
}
