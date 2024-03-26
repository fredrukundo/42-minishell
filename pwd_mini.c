/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_mini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:20:54 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:20:55 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_d *data)
{
	char	*temp;

	temp = getcwd(NULL, 0);
	printf("%s\n", temp);
	free(temp);
	data->exstatus = 0;
}
