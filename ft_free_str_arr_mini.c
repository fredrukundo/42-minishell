/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr_mini.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:07:53 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:07:54 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_str_arr(char ***arr)
{
	int	j;

	j = 0;
	while (*arr && (*arr)[j])
	{
		if ((*arr)[j])
		{
			free((*arr)[j]);
			(*arr)[j] = NULL;
		}
		j++;
	}
	if (*arr)
	{
		free(*arr);
		*arr = NULL;
	}
}
