/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:12:52 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:12:53 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*expand_vars(char *str, int ix, t_list *env);
static char	*value_change(int ix, char *str, char *value);
static char	*new_str(char *str, char *temp, size_t start, size_t end);

char	*uility(t_d *data, char *str, int i)
{
	if (str[i + 1] == '?')
		str = exit_status_expand(str, i, data->exstatus);
	else
		str = expand_vars(str, i, data->env);
	return (str);
}

static char	*expand_vars(char *str, int ix, t_list *env)
{
	char	*new;
	char	*temp;
	int		i;

	i = ix + 1;
	while (ft_strchr(VAR_BLOCK, str[i]) == NULL && str[i] != '\0')
		i++;
	temp = get_key(str, ix, i);
	while (env != NULL)
	{
		if (ft_strncmp(temp, env->content, ft_strlen(temp)) == 0)
		{
			temp = value_change(ft_strlen(temp), temp, (char *)env->content);
			break ;
		}
		env = env->next;
	}
	if (env == NULL)
		new = new_str(str, "", ix, i);
	else
		new = new_str(str, temp, ix, i);
	free(str);
	free(temp);
	return (new);
}

char	*get_key(char *str, int start, int end)
{
	char	*temp;

	temp = ft_calloc((end - (start + 1)) + 2, 1);
	ft_strlcpy(temp, &str[start + 1], (end - (start + 1)) + 1);
	temp[end - (start + 1)] = '=';
	temp[end - (start + 1) + 1] = '\0';
	return (temp);
}

static char	*value_change(int ix, char *str, char *value)
{
	char	*temp;
	int		i;

	free(str);
	i = 0;
	temp = ft_calloc(1, ft_strlen(value) - ix + 1 + 2);
	temp[i++] = '\"';
	while (value[ix] != '\0')
		temp[i++] = value[ix++];
	temp[i++] = '\"';
	temp[i] = '\0';
	return (temp);
}

static char	*new_str(char *str, char *temp, size_t start, size_t end)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	len;
	char	*new;

	len = (ft_strlen(str) - (end - (start + 1))) + ft_strlen(temp);
	if (len == 1)
		return (ft_strdup(""));
	new = ft_calloc((ft_strlen(str) - (end - (start + 1)))
			+ ft_strlen(temp), 1);
	i = -1;
	while (++i < start)
		new[i] = str[i];
	j = 0;
	while (i < ft_strlen(temp) + start)
		new[i++] = temp[j++];
	k = end;
	while (str[k] != '\0')
		new[i++] = str[k++];
	new[i] = '\0';
	return (new);
}
