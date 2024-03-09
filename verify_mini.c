/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_mini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:17:23 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:23:40 by hel-haia         ###   ########.fr       */
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
