/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:26:21 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/16 17:02:45 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	heredoc(t_redir *rd)
{
	int	fd;

	fd = open("/tmp/.to_hide", O_RDWR | O_CREAT | O_TRUNC, 0666);
	write(fd, rd->file_name, ft_strlen(rd->file_name));
	close(fd);
	fd = open("/tmp/.to_hide", O_RDONLY);
	return (fd);
}

int	open_file_out(char *path, int mode)
{
	int	fd;
	int	ret;

	if (mode == REDIR_OUT)
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (mode == DOUBLE_REDIR_OUT)
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (fd == -1)
		return (fd);
	ret = dup2(fd, STDOUT_FILENO);
	close(fd);
	return (ret);
}

int	open_file_in(t_redir *rd)
{
	int	fd;
	int	ret;

	if (rd->type == REDIR_IN)
	{
		if (access(rd->file_name, F_OK))
			return (-1);
		fd = open(rd->file_name, O_RDONLY);
	}
	else if (rd->type == DOUBLE_REDIR_IN)
		fd = heredoc(rd);
	if (fd == -1)
		return (fd);
	ret = dup2(fd, STDIN_FILENO);
	close(fd);
	return (ret);
}

int	redir_pipe(t_fd *fds, t_cmd *cmd)
{
	if (fds && !cmd->redir) // pb si redir plus pipe
	{
		if (cmd->pipe_out)
			dup2(fds[cmd->index].fd[1], STDOUT_FILENO);
		if (cmd->pipe_in)
			dup2(fds[cmd->index - 1].fd[0], STDIN_FILENO);
		return (0);
	}
	return (redir_loop(cmd));
}

int	redir_loop(t_cmd *cmd)
{
	t_redir	*head;
	int		ret;

	ret = 0;
	head = cmd->redir;
	while (head)
	{
		if (head->type == REDIR_OUT || head->type == DOUBLE_REDIR_OUT)
			ret = open_file_out(head->file_name, head->type);
		if (head->type == REDIR_IN || head->type == DOUBLE_REDIR_IN)
			ret = open_file_in(head);
		if (ret == -1)
			err_msg_rd(head->file_name);
		head = head->next;
	}
	return (ret);
}
