/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_mini.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:16:55 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:16:56 by hel-haia         ###   ########.fr       */
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
