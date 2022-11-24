# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 00:41:02 by rle-thie          #+#    #+#              #
#    Updated: 2022/11/21 11:29:56 by rle-thie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_INIT} ${SRCS_LEXER} ${SRCS_PARSER} ${SRCS_UTILS} ${SRCS_BUILT_IN} ${ENV} ${SRCS_EXEC} ${SRCS_IO_GESTION}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_INIT = $(addprefix srcs/init/, gc.c gc_utils.c \
										init.c init_env.c \
										secret_env.c \
										ft_open.c)

SRCS_LEXER = $(addprefix srcs/lexer/, lexer.c lexer_cmd.c \
									lexer_cmd_utils.c lexer_space.c \
									lexer_quote.c lexer_multiple_quote.c lexer_putin_allquote.c lexer_repalce_allquote.c lexer_double_quote.c \
									lexer_variable_env.c lexer_checkdouble_dollar.c lexer_expand_var.c lexer_expand_status.c lexer_expand_varchar.c)

SRCS_PARSER = $(addprefix srcs/parsing/, parser.c parsing_input_name.c \
								parser_flags.c parser_flags_utils.c \
								parser_args.c \
								parser_flags_args.c \
								parser_bool.c \
								parser_redir.c parser_redir_utils.c parser_redir_lst.c parser_redir_clean.c delete_chevron.c parser_redir_error.c parser_redir_lst_utils.c\
								parser_heredoc.c parser_herdoc_exp.c parser_heredoc_utils.c parser_heredoc_utils_utils.c)

SRCS_UTILS = $(addprefix srcs/utils/, ft_strjoin_gc.c \
										ft_print_token.c \
										ft_strdup_gc.c \
										ft_delete_lst.c \
										ft_printstr.c \
										ft_del_first_space.c \
										ft_exit_provisoire.c \
										signals.c \
										ft_create_one_char.c \
										ft_itoa_gc.c \
										ft_get_next_line.c)

SRCS_BUILT_IN = $(addprefix srcs/built_in/, my_echo.c my_pwd.c \
										my_env.c my_unset.c \
										my_export.c my_cd.c \
										my_exit.c my_cd_err.c)

SRCS_EXEC = $(addprefix srcs/exec/, paths.c exec.c env_to_char.c \
										builtin_ex.c utils.c)

SRCS_IO_GESTION = $(addprefix srcs/io_gestion/, pipe_ops.c \
											redir.c redir_two.c)

OBJDIR = objs

OBJS = $(addprefix ${OBJDIR}/, ${SRCS:.c=.o})

LIBFT = libft/libft.a

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

all: ${NAME}

${NAME}:	${OBJS}
		@make bonus -C libft
		${CC} ${CFLAGS} ${OBJS} -lreadline -o $@ ${LIBFT}

${OBJDIR}/%.o:%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	@make -C libft clean
	${RM} ${OBJDIR}

fclean: clean
	${RM} ${LIBFT}
	${RM} ${NAME}

re: fclean all

ree: fclean all
	clear
	./${NAME}

rc: fclean all
	${RM} ${OBJS} && clear

r: fclean all
	${RM} ${OBJS}
	valgrind --suppressions=ignoreleak --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes --verbose ./${NAME}

v: fclean all
	${RM} ${OBJS}
	clear
	valgrind --suppressions=ignoreleak --leak-check=full --show-leak-kinds=all --track-origins=yes ./${NAME}

t: fclean all
	${RM} ${OBJS}
	clear
	valgrind --suppressions=ignoreleak ./${NAME}
	
m: fclean all
	${RM} ${OBJS}
	clear
	valgrind --suppressions=ignoreleak --track-fds=yes --trace-children=yes ./${NAME}


.PHONY: all clean fclean re
