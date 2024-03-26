/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_mini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:21:25 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:21:26 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	syn_errors(int *lexer, int ix);

int	syn_analys(int *lexer, int len)
{
	int	i;

	i = -1;
	if (++i < len && len > 1)
		if (syn_errors(lexer, i) == 0)
			return (0);
	if (lexer[0] == PIPE || lexer[len - 1] == PIPE)
	{
		ft_putendl_fd("syntax error near unexpected token `|'", 2);
		return (0);
	}
	if (is_redirect(lexer[len - 1]) == 1)
	{
		ft_putendl_fd("syntax error near unexpected token `newline'", 2);
		return (0);
	}
	return (1);
}

static int	syn_errors(int *lexer, int ix)
{
	if (is_redirect(lexer[ix]) == 1 && lexer[ix + 1] != ARG)
	{
		if (lexer[ix + 1] == PIPE)
			ft_putendl_fd("syntax error near unexpected token `newline'", 2);
		else if (lexer[ix + 1] == INFILE)
			ft_putendl_fd("syntax error near unexpected token '<'", 2);
		else if (lexer[ix + 1] == OUTFILE)
			ft_putendl_fd("syntax error near unexpected token `>'", 2);
		else if (lexer[ix + 1] == HEREDOC)
			ft_putendl_fd("syntax error near unexpected token `<<'", 2);
		else if (lexer[ix + 1] == APPEND)
			ft_putendl_fd("syntax error near unexpected token `>>'", 2);
		return (0);
	}
	return (1);
}

int	is_redirect(int value)
{
	if (value == INFILE || value == OUTFILE
		|| value == HEREDOC || value == APPEND)
		return (1);
	return (0);
}
