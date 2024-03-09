/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr_mini.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:14:02 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:14:03 by hel-haia         ###   ########.fr       */
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
