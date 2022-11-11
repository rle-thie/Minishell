/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_gestion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:19:25 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/10 16:23:15 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IO_GESTION_H
# define IO_GESTION_H

//pipe_ops
t_fd	*open_pipes(void);
int		close_pipes(t_fd	*pipe_fd);

//redirs et pipe
int		open_file_out(char *path, int mode);
int		open_file_in(char *path, int mode);
void	redir_pipe(t_fd *fds, t_cmd *cmd);
int		redir_loop(t_cmd *cmd);

#endif