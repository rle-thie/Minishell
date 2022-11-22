/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:29:06 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/21 23:19:16 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UTILS_H
# define UTILS_H

char	*ft_strjoin_gc(char *s1, char *s2, t_data *data);
char	*ft_strjoinchar_gc(char *s1, char s2, t_data *data);
char	*ft_strdup_gc(const char *s, t_data *data);
char	*ft_itoa_gc(int n);
t_token	*delete_lst(t_token *lst);
t_token	*delete_lst_tok(t_token *lst);
char	*del_first_space(char *str);
char	*create_one_char(char c);

void	ft_print_token(t_token *token);
void	ft_print_formated(t_cmd *token);
void	ft_print_args(char **str);
void	print_bool(t_cmd *cmd);
char	*ft_printstr(char *str);
//sigs
void	handle_sigctlc(int sig);
void	sig_init(void);
void	sig_heredoc(int sig);
void	sig_handler_heredoc(void);
void	sig_quit(int sig);

// get_nxt_line
char	*get_next_line(int fd);

// provisoire
int	ft_exit_provisoire(char *str, int err);

#endif