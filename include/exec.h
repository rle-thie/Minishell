/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:14:18 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/18 15:37:13 by ldevy            ###   ########.fr       */
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

//exec
void	exec(char *cmd, char **args);
void	struct_to_char(void);
void	struct_to_char_p2(void);
void	reset_env_char(void);

#endif