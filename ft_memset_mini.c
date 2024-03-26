/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_mini.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:10:04 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:10:05 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
