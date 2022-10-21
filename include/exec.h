/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:14:18 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/21 17:25:25 by ldevy            ###   ########.fr       */
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
void	exec(char *cmd, char **args, t_fd *fds);
void	parent_process(char **av);
t_fd	*open_pipes(char **av);
int		close_pipes(t_fd	*pipe_fd);
int		nb_pipes(char **str);
int		cmd_number(void);

#endif