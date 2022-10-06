# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 00:41:02 by rle-thie          #+#    #+#              #
#    Updated: 2022/10/06 16:11:23 by ldevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_PARSING} ${SRCS_LOOP} ${SRCS_LEXER} ${SRCS_BUILT_IN} ${ENV}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_PARSING = $(addprefix srcs/parsing/, gc.c gc_utils.c \
										init.c)

SRCS_LEXER = $(addprefix srcs/lexer/, lexer.c)

SRCS_LOOP = $(addprefix srcs/loop/, loop.c)

SRCS_BUILT_IN = $(addprefix srcs/built_in/, my_echo.c my_pwd.c \
									my_env.c my_unset.c my_export.c)
ENV = $(addprefix srcs/init_env/, init_env.c)

OBJDIR = objs

OBJS = $(addprefix ${OBJDIR}/, ${SRCS:.c=.o})

LIBFT = libft/libft.a

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

RM = rm -rf

all: ${NAME}

${NAME}:	${OBJS}
		@make -C libft
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