/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_fd_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:12:18 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:12:19 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_files(int in, int out)
{
	if (in != -2)
		dup2(in, 0);
	if (out != -2)
		dup2(out, 1);
}

void	files_closing(int in, int out)
{
	if (in != -2)
		close(in);
	if (out != -2)
		close(out);
}
