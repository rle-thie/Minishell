/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:26:21 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/12 00:27:45 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	err_msg_rd(char *str)
{
	printf("bash: %s : %s", str, strerror(errno));
	exit (1);
}

int	heredoc(t_redir *rd)
{
	int	fd;

	(void)rd;
	fd = open("/tmp/.hd", O_RDWR | O_CREAT | O_TRUNC, 0644);
	write(fd, "lolololololololo\n", 18);
	return (fd);
}

int	open_file_out(char *path, int mode)
{
	int	fd;

	if (mode == REDIR_OUT)
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (mode == DOUBLE_REDIR_OUT)
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		return (1);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	open_file_in(t_redir *rd)
{
	int	fd;

	if (rd->type == REDIR_IN)
	{
		if (access(rd->file_name, F_OK))
			return (1);
		fd = open(rd->file_name, O_RDONLY);
	}
	else if (rd->type == DOUBLE_REDIR_IN)
		fd = heredoc(rd);
	if (fd == -1)
		return (1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

void	redir_pipe(t_fd *fds, t_cmd *cmd)
{
	if (fds && !cmd->redir)
	{
		if (cmd->pipe_out)
			dup2(fds[cmd->index].fd[1], STDOUT_FILENO);
		if (cmd->pipe_in)
			dup2(fds[cmd->index - 1].fd[0], STDIN_FILENO);
		close_pipes(fds);
		return ;
	}
	close_pipes(fds);
	redir_loop(cmd);
}

int	redir_loop(t_cmd *cmd)
{
	t_redir	*head;
	int		error;

	error = 0;
	head = cmd->redir;
	while (head)
	{
		if (head->type == REDIR_OUT || head->type == DOUBLE_REDIR_OUT)
			error = open_file_out(head->file_name, head->type);
		if (head->type == REDIR_IN || head->type == DOUBLE_REDIR_IN)
			error = open_file_in(head);
		if (error)
			err_msg_rd(head->file_name);
		head = head->next;
	}
	return (0);
}
//on doit ecrire dans chaque redir out 
//si une redir out fail on ne continue pas
