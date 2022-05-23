# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 00:41:02 by rle-thie          #+#    #+#              #
#    Updated: 2022/05/23 02:16:10 by rle-thie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ${SRCS_MAIN} ${SRCS_PARSING}

SRCS_MAIN = $(addprefix srcs/, main.c)

SRCS_PARSING = $(addprefix srcs/parsing/, gc.c gc_utils.c \
										init.c)

OBJDIR = objs

OBJS = $(addprefix ${OBJDIR}/, ${SRCS:.c=.o})

NAME = minishell

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: ${NAME}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -lreadline -o $@

${OBJDIR}/%.o:%.c
	@mkdir -p ${@D}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJDIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

rc: fclean all
	${RM} ${OBJS} && clear

.PHONY: all clean fclean re