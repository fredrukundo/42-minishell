/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:11:46 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:11:47 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*remove_quotes(char *str, int ix);

int	quotes_checks(t_d *data)
{
	t_list	*temp;
	char	*str;
	int		i;
	int		quoted;

	temp = ft_lstlast(data->token);
	str = ft_strdup((char *)data->token->content);
	i = -1;
	quoted = 0;
	while (str[++i] != '\0')
		quoted = is_quoted(str[i], quoted);
	free(str);
	if (quoted != 0)
	{
		ft_putendl_fd("line: non-closed quotes", 2);
		data->exstatus = 2;
		return (0);
	}
	return (1);
}

char	*find_remove_quotes(char *str)
{
	int	i;
	int	quoted;

	i = -1;
	quoted = 0;
	while (str[++i] != '\0')
	{
		quoted = is_quoted(str[i], quoted);
		if ((quoted == 2 || quoted == 0) && str[i] == D_QUOTES)
		{
			str = remove_quotes(str, i);
			i--;
		}
		else if ((quoted == 1 || quoted == 0) && str[i] == S_QUOTE)
		{
			str = remove_quotes(str, i);
			i--;
		}
	}
	return (str);
}

static char	*remove_quotes(char *str, int ix)
{
	char	*temp;
	int		i;
	int		j;

	temp = ft_calloc(1, ft_strlen(str));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (i == ix)
			i++;
		temp[j] = str[i];
		if (str[i] == '\0')
			break ;
		j++;
		i++;
	}
	free(str);
	return (temp);
}
