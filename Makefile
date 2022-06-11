# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 00:41:02 by rle-thie          #+#    #+#              #
#    Updated: 2022/06/11 01:53:13 by rle-thie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_PARSING} ${SRCS_LOOP} ${SRCS_LEXER}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_PARSING = $(addprefix srcs/parsing/, gc.c gc_utils.c \
										init.c)

SRCS_LEXER = $(addprefix srcs/lexer/, lexer.c lexer_cmd.c)

SRCS_LOOP = $(addprefix srcs/loop/, loop.c)

OBJDIR = objs

OBJS = $(addprefix ${OBJDIR}/, ${SRCS:.c=.o})

LIBFT = libft/libft.a

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra

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