/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tildes_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:11:52 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:11:53 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*find_expand_tilde(char *str, char *env);

void	check_tildes(t_list *token, char *line0)
{
	t_list	*temp;
	char	*str;

	temp = token;
	while (temp != NULL)
	{
		str = ft_strdup((char *)temp->content);
		str = find_expand_tilde(str, line0);
		free(temp->content);
		temp->content = ft_strdup(str);
		free(str);
		temp = temp->next;
	}
}

static char	*find_expand_tilde(char *str, char *line0)
{
	char	*temp;

	temp = NULL;
	if (ft_strlen(str) == 0 || str[0] != '~'
		|| (str[1] != '\0' && str[1] != '/'))
		return (str);
	else if (str[0] == '~' && str[1] == '\0')
	{
		temp = ft_calloc(1, ft_strlen(line0) + 1);
		ft_strlcpy(temp, line0, ft_strlen(line0) + 1);
	}
	else if (str[0] == '~' && str[1] == '/')
	{
		temp = ft_calloc(1, (ft_strlen(str) - 1) + ft_strlen(line0) + 1);
		ft_strlcpy(temp, line0, ft_strlen(line0) + 1);
		ft_strlcpy(&temp[ft_strlen(temp)], &str[1], ft_strlen(temp)
			+ (ft_strlen(str) - 1) + 1);
	}
	free(str);
	return (temp);
}
