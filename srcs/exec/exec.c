/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:36:19 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/22 16:22:01 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// je vais avoir besoin du nombre de cmds
void	parent_process(void)
{
	t_fd	*pipe_fd;
	t_cmd	*head;

	head = g_data.formated_cmd;
	//pipe_fd = open_pipes();
	while (head)
	{
		exec(pipe_fd, head);
		wait(NULL);
		head = head->next;
	}
	//close_pipes(pipe_fd);
}

void	child_process(t_fd *fds, t_cmd *cmd)
{
	int	ret;

	close_pipes(fds);
	ret = execve(path(cmd->cmd_name), cmd->args, g_data.env);
	exit(ret);
}

void	exec(t_fd *fds, t_cmd *cmd)
{
	int	pid;

	struct_to_char();
	pid = fork();
	if (pid == -1)
	{
		perror("bash :");
		return ;
	}
	if (pid == 0)
		child_process(fds, cmd);
	wait(NULL);
}

t_fd	*open_pipes(void)
{
	t_fd	*pipe_fd;
	int		size;
	int		i;

	size = cmd_number();
	if (size == 0)
		return (NULL);
	pipe_fd = ft_malloc(sizeof(t_fd) * (size + 1), &g_data);
	i = 0;
	while (i < size)
	{
		if (pipe(pipe_fd[i].fd) < 0)
		{
			perror("bash :");
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
	while (pipe_fd[i].fd[0] != -1)
	{
		if (close(pipe_fd[i].fd[0]) < 0)
			perror("bash :");
		if (close(pipe_fd[i].fd[1]) < 0)
			perror("bash :");
		i++;
	}
	ft_free(pipe_fd, &g_data);
	return (0);
}

int	cmd_number(void)
{
	t_cmd	*head;
	int		i;

	i = 0;
	head = g_data.formated_cmd;
	while (head->next)
	{
		i++;
		head = head->next;
	}
	if (head)
		i++;
	return (i);
}
