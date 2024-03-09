/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:15:16 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:15:17 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenuc(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	return (len);
}

static int	nmbr_of_word(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**splitstr;

	i = 0;
	splitstr = (char **)ft_calloc((nmbr_of_word(s, c) + 1), sizeof(char *));
	if (!splitstr)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			splitstr[i] = (char *)ft_calloc((lenuc(s, c) + 1), sizeof(char));
			if (!splitstr[i])
				return (NULL);
			j = 0;
			while (*s != c && *s)
				splitstr[i][j++] = *s++;
			i++;
		}
	}
	return (splitstr);
}
