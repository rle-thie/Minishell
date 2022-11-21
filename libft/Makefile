# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 17:18:32 by rle-thie          #+#    #+#              #
#    Updated: 2022/11/21 11:26:51 by rle-thie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_substr.c ft_strncmp.c ft_atoi.c ft_split.c \
		ft_strchr.c ft_putchar_fd.c ft_putnbr_fd.c \
		ft_itoa.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c \
		ft_strrchr.c ft_memset.c ft_strdup.c \
		ft_toupper.c ft_putendl_fd.c ft_isdigit.c ft_strtrim.c \
		ft_strlen.c ft_isprint.c ft_memcpy.c ft_strmapi.c \
		ft_tolower.c ft_strnstr.c ft_putstr_fd.c ft_bzero.c \
		ft_striteri.c ft_isalnum.c ft_isalpha.c ft_memchr.c \
		ft_memmove.c ft_strjoin.c ft_isascii.c

SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
			ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
			ft_lstclear.c ft_lstiter.c ft_lstmap.c

NAME = libft.a

OBJDIR = libft_objs

CC = gcc

FLAGS = -Wall -Werror -Wextra

OBJ = $(addprefix ${OBJDIR}/, ${SRC:.c=.o})

# OBJ_BONUS = ${SRC_BONUS:.c=.o}

OBJ_BONUS = $(addprefix ${OBJDIR}/, ${SRC_BONUS:.c=.o})

RM = rm -rf

all:	${NAME}

${NAME}:	${OBJ}
	ar -rcs ${NAME} ${OBJ}

bonus: ${OBJ} ${OBJ_BONUS}
	ar -rcs ${NAME} ${OBJ} ${OBJ_BONUS}
	
${OBJDIR}/%.o:%.c
	@mkdir -p ${@D}
	${CC} ${FLAGS} -I includes -c $< -o $@

clean: 
	${RM} ${OBJDIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re 
