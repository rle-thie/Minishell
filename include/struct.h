/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:49:57 by rle-thie          #+#    #+#             */
/*   Updated: 2022/06/09 13:51:22 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCT_H
# define STRUCT_H

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;
typedef struct	s_token t_token;
typedef enum e_token_type t_token_type;


enum	e_token_type
{
	WORD = 1,
	LETTER = 2,
	DQUOTE = '"',
	QUOTE = '\'',
	PIPE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	DGREATER = 8,
	HERE_DOC = 9,
	DOLLAR = '$',
	WHITE_SPACE = 11,
	IN_DQUOTE = 12,
	IN_QUOTE = 13,
	CMD = 14,
	ARG = 15,
	HERE_DOC_EXPEND = 16,
	JSP = 666
};

struct	s_token
{
	struct s_token		*prev;
	char				c;
	t_token_type		type;
	struct s_token		*next;
};

struct	s_garbage
{
	struct s_garbage	*prev;
	void				*ptr;
	struct s_garbage	*next;
};

struct s_data
{
	struct s_garbage *garb;
	char **env;
	struct	s_token *token;
};


#endif