/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_mini.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:05:31 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:05:32 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_expand_vars(char *str, t_d *data)
{
	int	quoted;
	int	i;

	quoted = 0;
	i = -1;
	while (str[++i] != '\0')
	{
		quoted = is_quoted(str[i], quoted);
		if (quoted == 0 && (str[i] == '$' && str[i + 1] != '\0'
				&& str[i + 1] != ' ' && str[i + 1] != '$'))
			str = uility(data, str, i);
		else if (quoted == 2 && (str[i] == '$' && str[i + 1] != '\0'
				&& ft_strchr(VAR_BLOCK, str[i + 1]) == NULL))
			str = uility(data, str, i);
		if (str[0] == '\0')
			break ;
	}
	return (str);
}
