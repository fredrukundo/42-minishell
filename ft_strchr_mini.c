/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_mini.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:15:21 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:15:22 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && ch == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
