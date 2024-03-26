/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:06:16 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:06:17 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	key_check(char *str)
{
	if (str == NULL)
		return (0);
	if (ft_isalpha(str[0]) != 1 && str[0] != '_')
	{
		printf("aaaa\n");
		return (0);
	}
	return (1);
}

void	export_print(t_list *export)
{
	char	**arr;

	while (export)
	{
		arr = key_value_spliting((char *)export->content, '=');
		if (arr[1])
			printf("declare -x %s=\"%s\"\n", arr[0], arr[1]);
		else
			printf("declare -x %s=\"\"\n", arr[0]);
		ft_free_str_arr(&arr);
		export = export->next;
	}
}
