/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_lst_mini.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:19:10 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:19:11 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_lst(t_list *lst)
{
	void	*tmp;

	tmp = lst->content;
	lst->content = lst->next->content;
	lst->next->content = tmp;
}
