/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_split_key_and_value_mini.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:05:52 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:05:53 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**words_seperation(char **strs, int size, char *s, char c);
static void	is_equal(int *count, int *temp, char *s, int c_word);
static char	*stringcpy(char *s, int temp, int count);

char	**key_value_spliting(char *str, char c)
{
	char	**strs;
	int		pos;
	int		size;
	int		equal_check;

	if (str == NULL)
		return (NULL);
	pos = -1;
	size = 0;
	equal_check = 0;
	while (str[++pos] != '\0' && equal_check == 0)
	{
		if (str[pos] != c && (str[pos + 1] == c || str[pos + 1] == '\0'))
		{
			size++;
			if (str[pos + 1] == c && str[pos + 2] != '\0')
				size++;
			equal_check = 1;
		}
	}
	strs = malloc((size + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	strs = words_seperation(strs, size, str, c);
	return (strs);
}

static char	**words_seperation(char **strs, int size, char *s, char c)
{
	int	count;
	int	c_word;
	int	temp;
	int	equal_check;

	count = 0;
	c_word = -1;
	equal_check = 0;
	while (++c_word < size)
	{
		temp = count;
		is_equal(&count, &temp, s, c_word);
		if (equal_check == 0)
			while (s[temp] != c && s[temp] != '\0')
				temp++;
		else if (equal_check == 1)
			while (s[temp] != '\0')
				temp++;
		if (s[temp] == c)
			equal_check = 1;
		strs[c_word] = stringcpy(s, temp, count);
		count = temp;
	}
	strs[c_word] = NULL;
	return (strs);
}

static void	is_equal(int *count, int *temp, char *s, int c_word)
{
	if (s[*count] == '=')
	{
		if (c_word != 0)
			*count = *count + 1;
		*temp = *temp + 1;
	}
}

static char	*stringcpy(char *s, int temp, int count)
{
	char	*str;

	str = malloc((temp - count + 1) * sizeof(char));
	ft_memcpy((void *)str, (const void *)&s[count], temp - count);
	str[temp - count] = '\0';
	return (str);
}
