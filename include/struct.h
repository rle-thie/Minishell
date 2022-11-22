/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:49:57 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/21 23:14:14 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;
typedef struct s_token		t_token;
typedef struct s_cmd		t_cmd;
typedef enum e_token_type	t_token_type;
typedef struct s_env		t_env;
typedef struct s_redir		t_redir;
typedef struct s_opened		t_opened;

enum	e_token_type
{
	WORD = 1,
	LETTER = 2,
	DQUOTE = '"',
	QUOTE = '\'',
	PIPE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	DOUBLE_REDIR_IN = 73,
	DOUBLE_REDIR_OUT = 79,
	REDIR = 67,
	DGREATER = 8,
	HERE_DOC = 9,
	DOLLAR = '$',
	WHITE_SPACE = 11,
	IN_DQUOTE = 12,
	IN_QUOTE = 13,
	CMD = 14,
	ARG = 15,
	HERE_DOC_EXPEND = 16,
	JSP = 666,
	FT_ERROR = 667
};

typedef struct s_builtin
{
	char	*nom;
	int		(*ptr_fct)();
}t_builtin;

typedef struct s_sigs
{
	struct sigaction	sint;
	struct sigaction	sexit;
	struct sigaction	sextwo;
}	t_sigs;

struct	s_token
{
	struct s_token		*prev;
	char				c;
	char				*str;
	t_token_type		type;
	struct s_token		*next;
};

struct	s_cmd
{
	struct s_cmd		*prev;
	struct s_cmd		*next;
	struct s_redir		*redir;
	char				*cmd_name;
	char				*flags;
	char				**args;
	int					nbr_args;
	char				**flags_and_args;
	int					bool_redir_out;
	int					bool_redir_in;
	int					pipe_in;
	int					pipe_out;
	int					index;
};

struct	s_garbage
{
	struct s_garbage	*prev;
	void				*ptr;
	struct s_garbage	*next;
};

struct s_env
{
	t_env	*next;
	t_env	*prev;
	char	*str;
	char	*name;
};

struct s_redir
{
	t_redir			*next;
	t_redir			*prev;
	char			*file_name;
	t_token_type	type;
	int				index;
};

struct	s_opened
{
	struct s_opened	*prev;
	int				fd;
	struct s_opened	*next;
};

struct s_data
{
	t_garbage	*garb;
	t_opened	*opened;
	t_env		*env_head;
	char		**env;
	t_token		*token;
	t_token		*cmd;
	t_cmd		*formated_cmd;
	int			status;
	int			error;
	t_builtin	*tab;
	t_sigs		sig;
	int			pid;
};

typedef struct s_fd
{
	int	fd[2];
}	t_fd;

#endif