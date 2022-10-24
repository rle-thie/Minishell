/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:49:57 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/24 15:35:26 by ldevy            ###   ########.fr       */
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
	char				*str;
	t_token_type		type;
	struct s_token		*next;
};

struct	s_cmd
{
	struct s_cmd		*prev;
	struct s_cmd		*next;
	char				*cmd_name;
	char				*flags;
	char				**args;
	int					nbr_args;
	char				**flags_and_args;
	char				**redir_in;
	char				**redir_out;
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
struct s_data
{
	t_garbage	*garb;
	t_env		*env_head;
	char		**env;
	t_token 	*token;
	t_token 	*cmd;
	t_cmd		*formated_cmd;
};
typedef struct s_fd
{
	int	fd[2];
}	t_fd;
 
#endif