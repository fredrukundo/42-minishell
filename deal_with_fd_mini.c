/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_with_fd_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:02:14 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:02:15 by frukundo         ###   ########.fr       */
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
