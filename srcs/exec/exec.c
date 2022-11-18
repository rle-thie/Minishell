/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:36:19 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/18 12:47:38 by ldevy            ###   ########.fr       */
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

	signal(SIGINT, SIG_IGN);
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
	{
		if (WIFSIGNALED(status))
			g_data.status = WTERMSIG(status) + 128;
		if (WIFEXITED(status))
			g_data.status = WEXITSTATUS(status);
	}
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
	int		ret;
	char	*pa;

	ret = 0;
	pa = path(cmd->cmd_name);
	redir_pipe(fds, cmd);
	close_pipes(fds);
	if (is_builtin(cmd))
	{
		ret = builtin_exec(cmd);
		exit(ret);
	}
	if (!pa)
	{
		printf("%s: command not found\n", cmd->cmd_name);
		exit(127);
	}
	ret = execve(pa, cmd->flags_and_args, g_data.env);
	perror("bash ");
	if (!find_path_str())
		ret = 127;
	else if (!access(pa, F_OK) && access(pa, X_OK))
		ret = 126;
	ft_free(pa, &g_data);
	exit(ret);
}
