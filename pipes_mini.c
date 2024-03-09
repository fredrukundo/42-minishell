/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:16:49 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:16:50 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	closing_pipes(t_arg *arg)
{
	close(arg->fd1[0]);
	close(arg->fd1[1]);
	close(arg->fd2[0]);
	close(arg->fd2[1]);
}

void	piping(t_arg *arg)
{
	if (arg->ix % 2 == 0)
	{
		close(arg->fd2[0]);
		close(arg->fd2[1]);
		pipe(arg->fd2);
	}
	else
	{
		close(arg->fd1[0]);
		close(arg->fd1[1]);
		pipe(arg->fd1);
	}
}
