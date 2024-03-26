/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_mini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:14:59 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:15:00 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	dest_len = (size_t)ft_strlen(dest);
	src_len = (size_t)ft_strlen((char *)src);
	if (size <= dest_len)
		return (size + src_len);
	else
	{
		i = 0;
		while (src[i] != '\0' && (dest_len + 1) < size)
		{
			dest[dest_len] = src[i];
			dest_len++;
			i++;
		}
		dest[dest_len] = '\0';
	}
	return (dest_len + ft_strlen((char *)(&src[i])));
}
