# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frukundo <frukundo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/26 20:20:30 by frukundo          #+#    #+#              #
#    Updated: 2024/03/26 20:20:31 by frukundo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
RD = /Users/$(USER)/.brew/Cellar/readline/8.2.10/lib
RDI = /Users/$(USER)/.brew/Cellar/readline/8.2.10/include
FLAGS = $(RD) $(LIBFT)/libft.a
CFLAGS = -Wall -Wextra -Werror -I $(LIBS) -I $(RDI)

LIBFT = ./libft/
LIBS = ./include
HEADER = ./include/libft.h ./include/minishell.h

RM = rm -f
FILES = main_mini.c \
		init_utils_mini.c \
		ft_strncmp_mini.c \
		ft_free_str_arr_mini.c \
		ft_atol_mini.c \
		ft_itoa_mini.c \
		ft_isalpha_mini.c \
		ft_arrsize_mini.c \
		ft_lstlast_bonus_mini.c \
		ft_lstnew_bonus_mini.c \
		ft_swap_lst_mini.c \
		ft_lstadd_back_bonus_mini.c \
		ft_lstsize_bonus_mini.c \
		ft_memcpy_mini.c \
		ft_putstr_fd_mini.c \
		ft_memset_mini.c \
		ft_printf_fd_mini.c \
		ft_putchar_fd_mini.c \
		ft_putendl_fd_mini.c \
		ft_strcmp_mini.c \
		ft_split_mini.c \
		ft_strchr_mini.c \
		ft_strdigit_mini.c \
		ft_strdup_mini.c \
		ft_strjoin_mini.c \
		ft_strlen_mini.c \
		ft_strlcpy_mini.c \
		ft_strlcat_mini.c \
		ft_isdigit_mini.c \
		ft_calloc_mini.c \
		execute_builtin_mini.c \
		exit_mini.c \
		env_mini.c \
		pwd_mini.c \
		unset_mini.c \
		export_mini.c \
		export_utils_mini.c \
		export_split_key_and_value_mini.c \
		echo_mini.c \
		cd_mini.c \
		signal_mini.c \
		token_mini.c \
		lexer_mini.c \
		syntax_mini.c \
		fix_input_mini.c \
		expansion_mini.c \
		expand_utils_mini.c \
		check_quotes_mini.c \
		check_tildes_mini.c \
		check_exit_status_mini.c \
		exec_mini.c \
		child_process_mini.c \
		finally_execute_mini.c \
		child_dups_mini.c \
		pipes_mini.c \
		get_cmd_and_builtin_mini.c \
		verify_mini.c \
		wait_all_process_mini.c \
		files_mini.c \
		deal_with_fd_mini.c \
		here_doc_mini.c \
		frees_mini.c
		
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME):$(OBJS) 
	cc $(CFLAGS) -lreadline -L $(RD) $(OBJS) -o $(NAME)
	
%.o : %.c $(HEADER)
	cc $(CFLAGS) -I $(RDI)  -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
