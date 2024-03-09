/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit_status_mini.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:11:41 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:11:42 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*exit_status_expand(char *str, int ix, int exstatus)
{
	char	*new;
	char	*temp;
	int		i;
	int		j;
	int		buffer;

	temp = ft_itoa(exstatus);
	new = ft_calloc(ft_strlen(temp) + (ft_strlen(str) - 2) + 1, 1);
	i = -1;
	while (++i < ix)
		new[i] = str[i];
	buffer = i + 2;
	j = 0;
	while (temp[j] != '\0')
		new[i++] = temp[j++];
	while (str[buffer] != '\0')
		new[i++] = str[buffer++];
	new[i] = '\0';
	free(str);
	free(temp);
	return (new);
}
