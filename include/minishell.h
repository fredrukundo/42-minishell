/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 03:11:30 by hel-haia          #+#    #+#             */
/*   Updated: 2024/02/28 04:24:57 by frukundo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <errno.h>
# include <libc.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/stat.h>

/* Characteres */
# define METACHAR "<>| "
# define VAR_BLOCK " <>|?\'\"/$"
# define BLANK "\t\n\v\f\r "
# define S_QUOTE '\''
# define D_QUOTES '\"'

/* Error defines */
# define SUCCESS 0
# define FAILURE 1
# define ERRBUILTIN 2
# define ERRCMD_NOTEXEC 126
# define ERRCMD_NOTFOUNT 127
# define ERR_INVALIDARG 128
# define ERR_CTRLC 130

/* Lexer */
enum	e_lexeme
{
	INFILE = 1,
	OUTFILE,
	HEREDOC,
	APPEND,
	PIPE,
	BUILTIN,
	CMD,
	ARG
};

typedef struct s_exec
{
	char			**cmd;
	int				lx;
	int				in;
	int				out;
}			t_ex;

typedef struct t_arg
{
	int		ix;
	int		fd1[2];
	int		fd2[2];
}			t_arg;

int	*g_sig;

typedef struct s_data
{
	char	*line;
	char	*line0;
	t_list	*env;
	t_list	*token;
	int		*lexer;
	t_ex	*exec;
	int		is_cmd;
	int		is_builtin;
	int		proc_nb;
	int		built_chck;
	t_arg	*arg;
	int		exstatus;
	int		*herdc;
}			t_d;

/* Init */
void	env_cpy(t_list **list, char **env, t_d *data);
void	readline_set(t_d *data);

/* Signal */
void	readline_signs(int signal);
void	sig_ignore(void);
void	sig_default(void);
void	sig_heredoc(int signal);
int		*hrdc_flg(void);

/* Token and syntax*/
int		tokenizing(t_d *data);
int		lex_analysis(t_d *data);
int		syn_analys(int *lexer, int len);
int		is_quoted(char c, int identifier);
int		is_redirect(int value);

/* Fix input */
int		quotes_checks(t_d *data);
void	check_value(t_d *data);
char	*exit_status_expand(char *str, int ix, int exstatus);
char	*find_expand_vars(char *str, t_d *data);
char	*uility(t_d *data, char *str, int i);
void	check_tildes(t_list *token, char *line0);
char	*find_remove_quotes(char *str);
char	*check_heredoc_var(char *str, t_d *data);
char	*get_key(char *str, int start, int end);
char	*is_herdoc(char *str, t_d *data);

/* Exec */
void	execute(t_d *data);
void	process_children(t_d *data, t_list *token, int *lexer, pid_t *pids);
void	handle_pipes(t_d *data);
void	cmd_args_getter(t_list *token, int *lexer, t_d *data);
void	excecuting(t_d *data, int fd[], pid_t *pids);
void	closing_pipes(t_arg *arg);
void	piping(t_arg *arg);
void	execute_builtin(t_d *data, t_ex *exec, pid_t *pids);
void	process_waiting(t_d *data, pid_t *pids, int flag);
void	permission_verification(char *copy, char **cmd, char **env);
int		verif(int result, char *str, char **cmd, char **env);

/* Builtin */
void	ft_exit(t_d *data, pid_t *pids, char **arg);
void	ft_env(t_d *data, char **arg);
void	ft_pwd(t_d *data);
void	ft_buitin(t_d *data, char **arg);
void	ft_export(t_d *data, char **arg);
char	**key_value_spliting(char *str, char c);
int		key_check(char *str);
void	export_print(t_list *export);
void	ft_echo(t_d *data, char **arg);
void	builtin_cd(t_d *data, char **arg);

/* Redirect */
int		check_files(t_list *token, int *lexer, int *in, int *out);
void	redirect_files(int in, int out);
void	files_closing(int in, int out);
int		hrdc_name_ch(t_d *data);

/* Free */
void	free_0(char **path, char **env, t_d *data, pid_t *pids);
void	free_1(t_d *data, pid_t *pids);
void	free_all(t_d *data);
void	lst_free(t_list *list);
void	free_2(t_ex *exec);

#endif