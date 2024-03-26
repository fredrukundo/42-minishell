/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_input_mini.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:06:44 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:06:45 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*to_value(char *str, char *key, char *value);
static char	*search_value(t_list *env, char *temp, char *new);

void	check_value(t_d *data)
{
	t_list	*temp;
	char	*str;

	temp = data->token;
	while (temp != NULL)
	{
		str = ft_strdup((char *)temp->content);
		str = find_expand_vars(str, data);
		free(temp->content);
		temp->content = ft_strdup(str);
		free(str);
		temp = temp->next;
	}
	temp = data->token;
	check_tildes(temp, data->line0);
	temp = data->token;
	while (temp != NULL)
	{
		str = ft_strdup((char *)temp->content);
		str = find_remove_quotes(str);
		free(temp->content);
		temp->content = ft_strdup(str);
		free(str);
		temp = temp->next;
	}
}

char	*is_herdoc(char *str, t_d *data)
{
	int		i;
	int		buffer;
	char	*temp;
	char	*new;

	i = -1;
	new = ft_strdup(str);
	while (new[++i] != '\0')
	{
		if (new[i] == '$')
		{
			buffer = i + 1;
			while (str[buffer] != '\0' && ft_strchr(VAR_BLOCK, str[buffer])
				== NULL)
				buffer++;
			temp = get_key(str, i, buffer);
			new = search_value(data->env, temp, new);
			if (new[i] == '\0')
				break ;
		}
	}
	free(str);
	return (new);
}

static char	*search_value(t_list *env, char *temp, char *new)
{
	while (env != NULL)
	{
		if (ft_strncmp(temp, env->content, ft_strlen(temp)) == 0)
		{
			new = to_value(new, temp,
					(char *)&env->content[ft_strlen(temp)]);
			break ;
		}
		if (env->next == NULL)
			new = to_value(new, temp, "");
		env = env->next;
	}
	return (new);
}

static char	*to_value(char *str, char *key, char *value)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	new = ft_calloc(ft_strlen(str) - ft_strlen(key) + ft_strlen(value) + 1, 1);
	i = -1;
	while (str[++i] != '$' && str[i] != '\0')
		new[i] = str[i];
	k = i + ft_strlen(key);
	j = 0;
	while (value[j] != '\0')
		new[i++] = value[j++];
	while (str[k] != '\0')
		new[i++] = str[k++];
	new[i] = '\0';
	free(key);
	free(str);
	return (new);
}
