/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:36:19 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/08 17:05:58 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parent_process(void)
{
	t_fd	*pipe_fd;
	t_cmd	*head;
	int		error;

	error = 0;
	g_data.status = 0;
	head = g_data.formated_cmd;
	if (!head)
		return ;
	pipe_fd = open_pipes();
	if (!pipe_fd)
		error = 1;
	while (head)
	{
		if (pipe_fd || (!pipe_fd && head->index == cmd_number() - 1))
			exec(pipe_fd, head);
		head = head->next;
	}
	close_pipes(pipe_fd);
	waiting_fct(get_last_cmd(), error);
}

void	waiting_fct(t_cmd *last, int error)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < cmd_number() && !(cmd_number() == 1 && is_builtin(last)))
	{
		wait(&status);
		if (error)
			break ;
		i++;
	}
	if (!(cmd_number() == 1 && is_builtin(last)))
		g_data.status = WEXITSTATUS(status);
}

void	exec(t_fd *fds, t_cmd *cmd)
{
	int	pid;

	if (is_builtin(cmd) && cmd_number() == 1)
	{
		g_data.status = builtin_exec(cmd);
		return ;
	}
	struct_to_char();
	pid = fork();
	if (pid == -1)
	{
		perror("bash :");
		return ;
	}
	if (pid == 0)
		child_process(fds, cmd);
}

void	child_process(t_fd *fds, t_cmd *cmd)
{
	int	ret;

	ret = 0;
	if (fds)
	{
		if (cmd->pipe_out)
			dup2(fds[cmd->index].fd[1], STDOUT_FILENO);
		if (cmd->pipe_in)
			dup2(fds[cmd->index - 1].fd[0], STDIN_FILENO);
	}
	close_pipes(fds);
	if (is_builtin(cmd))
	{
		ret = builtin_exec(cmd);
		exit(ret);
	}
	if (!path(cmd->cmd_name))
	{
		printf("%s: command not found\n", cmd->cmd_name);
		exit(127);
	}
	ret = execve(path(cmd->cmd_name), cmd->flags_and_args, g_data.env);
	perror(cmd->cmd_name);
	exit(ret);
}

t_fd	*open_pipes(void)
{
	t_fd	*pipe_fd;
	int		size;
	int		i;

	size = cmd_number();
	if (size == 0)
		return (NULL);
	pipe_fd = ft_malloc(sizeof(t_fd) * (size), &g_data);
	i = 0;
	while (i < size - 1)
	{
		if (pipe(pipe_fd[i].fd) < 0)
		{
			perror("bash: start_pipeline: pgrp pipe:");
			pipe_fd[i].fd[0] = -1;
			close_pipes(pipe_fd);
			return (NULL);
		}
		i++;
	}
	pipe_fd[i].fd[0] = -1;
	return (pipe_fd);
}

int	close_pipes(t_fd *pipe_fd)
{
	int	i;

	i = 0;
	if (!pipe_fd)
		return (0);
	while (pipe_fd[i].fd[0] != -1)
	{
		if (close(pipe_fd[i].fd[0]) < 0)
			perror("bash: end_pipeline: pgrp pipe:");
		if (close(pipe_fd[i].fd[1]) < 0)
			perror("bash: end_pipeline: pgrp pipe:");
		i++;
	}
	ft_free(pipe_fd, &g_data);
	return (0);
}
