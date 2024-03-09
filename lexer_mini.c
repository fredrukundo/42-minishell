/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haia <hel-haia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:16:38 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 03:29:25 by hel-haia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	lexing(char *token, t_d *data, int ix);
static int	is_builtin(char *token);
static int	get_pos(int *lexer, int ix);
static int	check_cmd(int *lexer, int ix);

int	lex_analysis(t_d *data)
{
	t_list	*temp;
	int		i;

	data->lexer = ft_calloc(ft_lstsize(data->token), sizeof(int));
	temp = data->token;
	i = 0;
	while (temp != NULL)
	{
		data->lexer[i] = lexing(temp->content, data, i);
		temp = temp->next;
		i++;
	}
	if (syn_analys(data->lexer, ft_lstsize(data->token)) == 0)
	{
		data->exstatus = 258;
		return (0);
	}
	return (1);
}

static int	lexing(char *token, t_d *data, int ix)
{
	if (ft_strlen(token) == 1)
	{
		if (token[0] == '<')
			return (INFILE);
		else if (token[0] == '>')
			return (OUTFILE);
		else if (token[0] == '|')
			return (PIPE);
	}
	if (ft_strlen(token) == 2)
	{
		if (token[0] == '<')
			return (HEREDOC);
		else if (token[0] == '>')
			return (APPEND);
	}
	if (get_pos(data->lexer, ix) == 1 && is_builtin(token) == 1)
		return (BUILTIN);
	else if (get_pos(data->lexer, ix) == 1)
		return (CMD);
	return (ARG);
}

static int	get_pos(int *lexer, int ix)
{
	if (ix == 0)
		return (1);
	if (lexer[ix - 1] == PIPE)
		return (1);
	if (check_cmd(lexer, ix) == 0)
		return (0);
	if (ix - 2 >= 0)
	{
		if (lexer[ix - 2] == HEREDOC)
			return (1);
		if (lexer[ix - 2] == INFILE)
			return (1);
		if (lexer[ix - 2] == OUTFILE)
			return (1);
		if (lexer[ix - 2] == APPEND)
			return (1);
	}
	return (0);
}

static int	check_cmd(int *lexer, int ix)
{
	int	cmd_check;

	cmd_check = 0;
	while (--ix >= 0)
	{
		if (lexer[ix] == PIPE)
			return (1);
		else if (lexer[ix] == CMD || lexer[ix] == BUILTIN)
			return (0);
	}
	return (1);
}

static int	is_builtin(char *token)
{
	if ((ft_strcmp(token, "echo") == 0))
		return (1);
	if ((ft_strcmp(token, "cd") == 0))
		return (1);
	if ((ft_strcmp(token, "pwd") == 0))
		return (1);
	if ((ft_strcmp(token, "export") == 0))
		return (1);
	if ((ft_strcmp(token, "unset") == 0))
		return (1);
	if ((ft_strcmp(token, "env") == 0))
		return (1);
	if ((ft_strcmp(token, "exit") == 0))
		return (1);
	return (0);
}
