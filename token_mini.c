/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:21:34 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:21:35 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	size_oftoken(char *token);
static void	token_cpy(int len, t_d *data, int index);
static int	metacharacter(char c);

int	tokenizing(t_d *data)
{
	int		i;
	int		len;

	i = 0;
	while (ft_strchr(BLANK, data->line[i]) != NULL && data->line[i] != '\0')
		i++;
	if (data->line[i] == '\0')
		return (0);
	i = -1;
	while (data->line[++i] != '\0')
	{
		while (ft_strchr(BLANK, data->line[i]) != NULL
			&& data->line[i] != '\0')
			i++;
		if (data->line[i] == '\0')
			break ;
		len = size_oftoken(&data->line[i]);
		token_cpy(len, data, i);
		i += len - 1;
	}
	if (lex_analysis(data) == 0)
		return (0);
	return (1);
}

static int	size_oftoken(char *token)
{
	int	i;
	int	quoted;
	int	metachar;

	metachar = metacharacter(token[0]);
	quoted = is_quoted(token[0], 0);
	i = 0;
	while (token[++i] != '\0')
	{
		if (metachar == 1)
		{
			if (token[i] == token[i - 1])
				return (2);
			return (1);
		}
		else if (quoted == 0)
		{
			if (token[i] == ' ' || metacharacter(token[i]) == 1)
				return (i);
			quoted = is_quoted(token[i], quoted);
		}
		else
			quoted = is_quoted(token[i], quoted);
	}
	return (i);
}

static void	token_cpy(int len, t_d *data, int index)
{
	char	*temp;

	temp = ft_calloc((len + 1), sizeof(char));
	ft_strlcpy(temp, &data->line[index], len + 1);
	ft_lstadd_back(&data->token, ft_lstnew(ft_strdup(temp)));
	free(temp);
}

int	is_quoted(char c, int identifier)
{
	if (identifier == 0)
	{
		if (c == S_QUOTE)
			return (1);
		else if (c == D_QUOTES)
			return (2);
	}
	else if (identifier == 1)
	{
		if (c != S_QUOTE)
			return (1);
	}
	else if (identifier == 2)
	{
		if (c != D_QUOTES)
			return (2);
	}
	return (0);
}

static int	metacharacter(char c)
{
	if (ft_strchr(METACHAR, c) == NULL)
		return (0);
	return (1);
}
