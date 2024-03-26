/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_mini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:21:55 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:21:56 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	verif(int result, char *str, char **cmd, char **env)
{
	if (result == 0)
	{
		permission_verification(str, cmd, env);
		return (0);
	}
	return (-1);
}

void	permission_verification(char *copy, char **cmd, char **env)
{
	if (access(copy, X_OK) == 0)
		execve(copy, cmd, env);
}
