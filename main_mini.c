/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:20:11 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:20:12 by frukundo         ###   ########.fr       */
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
