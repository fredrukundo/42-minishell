/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_mini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:19:44 by frukundo          #+#    #+#             */
/*   Updated: 2024/03/26 20:19:45 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	hrdc_open(t_d *data, int size);
static int	file_open(char *file);
static void	hrdc_fill(int fd, char *end_msg, t_d *data);

int	hrdc_name_ch(t_d *data)
{
	int		i;
	int		size;
	t_list	*temp;

	i = -1;
	size = 0;
	temp = data->token;
	while (temp != NULL)
	{
		if (data->lexer[++i] == HEREDOC)
			size++;
		temp = temp->next;
	}
	if (size > 0)
		if (hrdc_open(data, size) == 0)
			return (0);
	if (*hrdc_flg() == 1)
	{
		data->exstatus = 130;
		return (0);
	}
	return (1);
}

static int	hrdc_open(t_d *data, int size)
{
	t_list	*temp;
	int		i;
	int		ix;
	int		backup;

	data->herdc = ft_calloc(sizeof(int), size);
	temp = data->token;
	i = -1;
	ix = 0;
	while (temp != NULL)
	{
		backup = dup(0);
		if (data->lexer[++i] == HEREDOC)
		{
			data->herdc[ix] = file_open((char *)temp->next->content);
			if (data->herdc[ix] == -1)
				return (0);
			hrdc_fill(data->herdc[ix],
				(char *)temp->next->content, data);
			close(data->herdc[ix++]);
		}
		dup2(backup, 0);
		temp = temp->next;
	}
	return (1);
}

static int	file_open(char *file)
{
	int		fd;
	char	*temp;

	temp = ft_strjoin("/tmp/", file);
	fd = open(temp, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	free(temp);
	if (fd < 0)
		return (-1);
	return (fd);
}

static void	hrdc_fill(int fd, char *end_msg, t_d *data)
{
	char	*temp;

	while (true)
	{
		signal(SIGINT, sig_heredoc);
		signal(SIGQUIT, SIG_IGN);
		temp = readline("> ");
		if (temp == NULL)
		{
			ft_putchar_fd('\n', 1);
			break ;
		}
		if (ft_strcmp(temp, end_msg) == 0)
		{
			free(temp);
			break ;
		}
		temp = is_herdoc(temp, data);
		ft_putendl_fd(temp, fd);
		free(temp);
	}
}
