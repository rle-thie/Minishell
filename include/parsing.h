/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:17:07 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/12 15:42:54 by rle-thie         ###   ########.fr       */
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

// variable d'env
t_token	*check_variable_env(t_token *cmd);
t_token	*check_double_dollar(t_token *cmd, int i, int len);
t_token	*expand_var(t_token *cmd);
char	*expand_status(char *str);
char	*expand_varchar(char *str, int i);

// quote
t_token	*check_quote(t_token *cmd);
t_token	*check_multiple_allquote(t_token *cmd);
t_token	*putin_allquote(t_token *cmd);
t_token	*replace_allquote(t_token *cmd);
t_token	*check_double_allquote(t_token *cmd);


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
t_redir	*format_redir_lst(t_redir *lst);
int		ft_strleni(char *str, int i);
int		check_one_redir(char *str);
// parser_redir_clean.c
t_redir	*clean_all_redir(t_redir *lst);
t_redir	*check_heredoc(t_redir *lst, char *content);
char	*expand_heredoc(char *str, int i);
// redir_utils.c
t_redir	*ft_create_redir(char *str);
t_redir	*add_back_redir(t_redir *token, char *str);
t_redir	*lst_put_start(t_redir *lst);
t_token	*lst_start_token(t_token *lst);
int		is_redir(t_token *cmd);
// heredoc
int		heredoc_loop_return(char *content, char *line, char *eof);
int		heredoc_loop(char **content, char *eof);
int		create_heredoc(char *str, char *content);
t_redir	*check_heredoc(t_redir *lst, char *content);
int		ft_strcmp(char *s1, char *s2);
// heredoc utils
void	sig_reset(void);
void	free_all(t_data *data);
int		exit_heredoc_fork(t_data *data, int dup_stdin);
void	exec_error(t_data *data);
int		no_line_return(int i, char *eof);
// heredoc utils utils
char	*del_last_n(char *str);
char	*put_heredoc(char *file);
void	copy_in_heredoc(int fd, char *s);
int		check_eof(char *line, char *eof);
// delete_chevron
t_redir	*delete_chevron(t_redir *lst);
int		check_redir_error(t_redir *lst);
int		is_valid_redir(t_redir *lst);
// parsing
void	parser(void);

#endif
