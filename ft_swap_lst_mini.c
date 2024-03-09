/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_lst_mini.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:16:16 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:16:17 by hel-haia         ###   ########.fr       */
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
