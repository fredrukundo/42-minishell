/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:20:43 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:20:44 by frukundo         ###   ########.fr       */
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
