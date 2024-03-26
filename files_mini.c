/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_mini.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:06:25 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:06:26 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	isfile_present(char *file);
static int	valid_filepermis(int lx, char *file);
static int	open_filered(int lx, char *file, int *in, int *out);
static int	isfile_present_0(char *temp, int lx);

int	check_files(t_list *token, int *lexer, int *in, int *out)
{
	t_list	*temp;
	int		i;
	int		result;

	*in = -2;
	*out = -2;
	i = -1;
	temp = token;
	while (temp->next != NULL && lexer[++i] != PIPE)
	{
		if (is_redirect(lexer[i]) == 1)
		{
			result = open_filered(lexer[i], (char *)temp->next->content, in,
					out);
			if (result == 2)
				return (2);
			if (result == 3)
				return (3);
			if (result == 4)
				return (4);
		}
		temp = temp->next;
	}
	return (1);
}

static int	open_filered(int lx, char *file, int *in, int *out)
{
	struct stat	file_info;
	char		*temp;

	temp = ft_strdup(file);
	if (stat(file, &file_info) == 0)
	{
		if (S_ISDIR(file_info.st_mode))
		{
			ft_printf_fd(2, "%s: Is a directory\n", file);
			return (4);
		}
	}
	if (lx == INFILE)
		*in = open(file, O_RDONLY);
	else if (lx == HEREDOC)
	{
		free(temp);
		temp = ft_strjoin("/tmp/", file);
		*in = open(temp, O_RDONLY);
	}
	else if (lx == OUTFILE)
		*out = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	else if (lx == APPEND)
		*out = open(file, O_RDWR | O_APPEND | O_CREAT, 0644);
	return (isfile_present_0(temp, lx));
}

static int	isfile_present(char *file)
{
	struct stat	file_info;

	if (stat(file, &file_info) != 0)
	{
		ft_printf_fd(2, "%s: No such file or directory\n", file);
		return (0);
	}
	return (1);
}

static int	valid_filepermis(int lx, char *file)
{
	if (lx == OUTFILE || lx == APPEND)
	{
		if (access(file, W_OK) != 0)
		{
			ft_printf_fd(2, "%s: Permission denied\n", file);
			return (0);
		}
	}
	else
	{
		if (access(file, R_OK) != 0)
		{
			ft_printf_fd(2, "%s: Permission denied\n", file);
			return (0);
		}
	}
	return (1);
}

static int	isfile_present_0(char *temp, int lx)
{
	if (isfile_present(temp) == 0)
	{
		free(temp);
		return (2);
	}
	if (valid_filepermis(lx, temp) == 0)
	{
		free(temp);
		return (3);
	}
	free(temp);
	return (1);
}
