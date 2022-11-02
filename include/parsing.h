/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:17:07 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/23 18:08:13 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSING_H
# define PARSING_H

// lexer
void	lexer(char *str, t_data *data);
void	create_cmd(t_token *cmd, t_token *token, t_data *data, int len);

// lexer_cmd_utils.c
char	*trans(char c, t_data *data);
t_token_type	select_type(char c);
void	fill_type(t_token *cmd, t_data *data);

// lexer_space.c
void	lexer_space(t_token *cmd);


// flags
char	*fill_flags(t_token *cmd);
// flags_utils.c
char	*put_tiret(char *str);

// args
char	**fill_args(t_token *cmd);

// flags & args
char	**fill_flags_args(char *flags, char **args, int nbr_args, char *cmd);

// booleen
void	add_bool_var(t_cmd	*format_cmd);

// redir.c
t_redir	*parse_redir(t_token *cmd);
// redir_parse_lst.c
void	format_redir_lst(t_redir *lst);
// redir_utils.c
t_redir	*ft_create_redir(char *str);
t_redir	*add_back_redir(t_redir *token, char *str);
t_redir	*lst_put_start(t_redir *lst);
t_token	*lst_start_token(t_token *lst);

// parsing
void	parser(void);

#endif