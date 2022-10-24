/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:36:19 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/24 18:42:47 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	parent_process(void)
{
	t_fd	*pipe_fd;
	t_cmd	*head;
	int		i;

	head = g_data.formated_cmd;
	pipe_fd = open_pipes();
	while (head)
	{
		exec(pipe_fd, head);
		head = head->next;
	}
	close_pipes(pipe_fd);
	i = 0;
	while (i < cmd_number())
	{
		printf("not waited\n");
		wait(NULL);
		printf("waited\n");
		i++;
	}
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
}

void	child_process(t_fd *fds, t_cmd *cmd)
{
	int	ret;
	
	if (cmd->pipe_out)
		dup2(fds[cmd->index].fd[1], STDOUT_FILENO);
	if (cmd->pipe_in)
		dup2(fds[cmd->index].fd[0], STDIN_FILENO);
	close_pipes(fds);
	ret = execve(path(cmd->cmd_name), cmd->flags_and_args, g_data.env);
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
			perror("pipe opening");
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
		if (pipe_fd[i].fd[0])
			if (close(pipe_fd[i].fd[0]) < 0)
				perror("pipe closing ");
		if (pipe_fd[i].fd[1])
			if (close(pipe_fd[i].fd[1]) < 0)
				perror("pipe closing ");
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

void	print_cmd(t_cmd *cmd)
{
	int	i;

	i = 0;
	printf("cmd name : %s\n", cmd->cmd_name);
	// while (cmd->args[i])
	// {
	// 	printf("cmd args : %s\n", cmd->args[i]);
	// 	i++;
	// }
	i = 0;
	while (cmd->flags_and_args[i])
	{
		printf("cmd args : %s\n", cmd->flags_and_args[i]);
		i++;
	}
	printf("cmd index %d\n", cmd->index);
	printf("cmd next %p\n", cmd->next);
	printf("cmd pipe in %d\n", cmd->bool_redir_out);
	printf("cmd pipe out %d\n", cmd->bool_redir_in);
}
