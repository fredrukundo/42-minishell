/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_dups_mini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:12:00 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:12:01 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	command_first(t_arg *arg);
static void	command_middle(t_arg *arg);
static void	command_last(t_arg *arg);

void	handle_pipes(t_d *data)
{
	if (data->proc_nb > 1)
	{
		if (data->arg->ix == data->proc_nb - 1)
			command_last(data->arg);
		else if (data->arg->ix == 0)
			command_first(data->arg);
		else
			command_middle(data->arg);
	}
	closing_pipes(data->arg);
}

static void	command_first(t_arg *arg)
{
	dup2(arg->fd1[1], 1);
}

static void	command_middle(t_arg *arg)
{
	if (arg->ix % 2 == 0)
	{
		dup2(arg->fd2[0], 0);
		dup2(arg->fd1[1], 1);
	}
	else
	{
		dup2(arg->fd1[0], 0);
		dup2(arg->fd2[1], 1);
	}
}

static void	command_last(t_arg *arg)
{
	if (arg->ix % 2 == 0)
		dup2(arg->fd2[0], 0);
	else
		dup2(arg->fd1[0], 0);
}
