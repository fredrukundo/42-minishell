/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:15:44 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:15:45 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*dest;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	dest = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcpy(dest + s1_len, s2, s2_len + 1);
	return (dest);
}
