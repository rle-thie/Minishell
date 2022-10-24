/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:14:18 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/24 18:32:05 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

//path
char	*path(char *cmd);
char	*make_path(char **test_path, char *cmd);
char	*exec_path_test(char *cmd, char *path);
void	free_split(char **paths);
char	*find_path_str(void);

//env_to_char
void	struct_to_char(void);
void	struct_to_char_p2(void);
void	reset_env_char(void);

//exec_logic
void	exec(t_fd *fds, t_cmd *cmd);
void	parent_process(void);
t_fd	*open_pipes(void);
int		close_pipes(t_fd	*pipe_fd);
int		cmd_number(void);
void	child_process(t_fd *fds, t_cmd *cmd);

//debug
void	print_cmd(t_cmd *cmd);
#endif