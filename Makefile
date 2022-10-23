# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 00:41:02 by rle-thie          #+#    #+#              #
#    Updated: 2022/10/20 19:10:03 by rle-thie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_INIT} ${SRCS_LEXER} ${SRCS_PARSER} ${SRCS_UTILS} ${SRCS_BUILT_IN} ${ENV}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_INIT = $(addprefix srcs/init/, gc.c gc_utils.c \
										init.c init_env.c)

SRCS_LEXER = $(addprefix srcs/lexer/, lexer.c lexer_cmd.c \
									lexer_cmd_utils.c lexer_space.c)

SRCS_PARSER = $(addprefix srcs/parsing/, parser.c \
										parser_flags.c parser_flags_utils.c \
										parser_args.c \
										parser_flags_args.c \
										parser_bool.c)

SRCS_UTILS = $(addprefix srcs/utils/, ft_strjoin_gc.c ft_print_token.c)

SRCS_BUILT_IN = $(addprefix srcs/built_in/, my_echo.c my_pwd.c \
									my_env.c my_unset.c my_export.c my_cd.c)

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

.PHONY: all clean fclean re