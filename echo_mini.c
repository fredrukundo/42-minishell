/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:12:23 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 04:25:51 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_nl(int n_check);
static int	verify_n(char *str);

void	ft_echo(t_d *data, char **arg)
{
	int	i;
	int	n_check;

	n_check = 0;
	i = 1;
	if (array_size(arg) > 1)
	{
		while (arg[i] != NULL && ft_strncmp(arg[i], "-n", 2) == 0)
		{
			if (verify_n(arg[i]) == 0)
				break ;
			i++;
			n_check = 1;
		}
		if (arg[i] != NULL)
		{
			while (i < array_size(arg) - 1)
				printf("%s ", arg[i++]);
			printf("%s", arg[i]);
		}
		print_nl(n_check);
	}
	else
		printf("\n");
	data->exstatus = 0;
}

void	print_nl(int n_check)
{
	if (n_check == 0)
		printf("\n");
}

static int	verify_n(char *str)
{
	int	i;

	i = 2;
	while (str[i] != '\0')
	{
		if (str[i++] != 'n')
			return (0);
	}
	return (1);
}
