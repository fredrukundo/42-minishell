/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:17:18 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:23:15 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	if_unset_present(t_d *data, char *arr);
static void	node_freeing(t_list *node, t_list *list);

void	if_unset_present(t_d *data, char *arr)
{
	t_list	*tmp;

	tmp = data->env;
	while (tmp)
	{
		if (ft_strncmp((char *)tmp->content, arr, ft_strlen(arr)) == 0)
		{
			node_freeing(tmp, data->env);
			break ;
		}
		tmp = tmp->next;
	}
}

static void	node_freeing(t_list *node, t_list *list)
{
	t_list	*temp;

	temp = list;
	while (temp->next != node)
		temp = temp->next;
	temp->next = temp->next->next;
	free(node->content);
	free(node);
}

void	ft_buitin(t_d *data, char **arg)
{
	int		i;

	i = 0;
	while (arg[++i] != NULL)
		if_unset_present(data, arg[i]);
	data->exstatus = 0;
}
