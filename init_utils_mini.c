/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_mini.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:16:33 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:16:34 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	readline_pars(t_d *data);
static void	readline_r(t_d *data);

int	*hrdc_flg(void)
{
	static int	heredoc_flag;

	return (&heredoc_flag);
}

void	env_cpy(t_list **list, char **env, t_d *data)
{
	int	i;

	i = -1;
	while (env[++i] != NULL)
	{
		ft_lstadd_back(list, ft_lstnew(ft_strdup(env[i])));
		if (ft_strncmp(env[i], "line0=", 5) == 0)
		{
			data->line0 = ft_calloc(1, ft_strlen(&env[i][5]) + 1);
			ft_strlcpy(data->line0, &env[i][5], ft_strlen(&env[i][5]) + 1);
		}
	}
}

void	readline_set(t_d *data)
{
	while (true)
	{
		signal(SIGINT, readline_signs);
		signal(SIGQUIT, SIG_IGN);
		data->token = NULL;
		data->lexer = NULL;
		data->herdc = NULL;
		data->line = readline("minishell$ ");
		if (data->line == NULL)
		{
			ft_putendl_fd("exit", 1);
			break ;
		}
		if (ft_strlen(data->line) >= 1)
			readline_pars(data);
		free(data->line);
	}
}

static void	readline_pars(t_d *data)
{
	add_history(data->line);
	if (tokenizing(data) == 1 && quotes_checks(data) == 1)
	{
		check_value(data);
		readline_r(data);
	}
	if (data->herdc != NULL)
		free(data->herdc);
	if (data->lexer != NULL)
		free(data->lexer);
	if (data->token != NULL)
		lst_free(data->token);
}

static void	readline_r(t_d *data)
{
	int		i;
	t_list	*temp;

	*hrdc_flg() = 0;
	if (hrdc_name_ch(data) == 1)
	{
		i = -1;
		data->proc_nb = 1;
		data->built_chck = 0;
		temp = data->token;
		while (temp != NULL)
		{
			if (data->lexer[++i] == PIPE)
				data->proc_nb++;
			if (data->proc_nb == 1 && data->lexer[i] == BUILTIN)
				data->built_chck = 1;
			temp = temp->next;
		}
		execute(data);
	}
}
