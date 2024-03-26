/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_mini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:02:45 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:02:46 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_d *data, char **arg)
{
	t_list	*temp;

	if (array_size(arg) > 1)
	{
		ft_printf_fd(2, "env: %s: No such file or directory\n", arg[1]);
		data->exstatus = 127;
		return ;
	}
	temp = data->env;
	while (temp != NULL)
	{
		if (temp->content && ft_strchr((char *)temp->content, '=') != NULL)
			printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}
	data->exstatus = 0;
}
