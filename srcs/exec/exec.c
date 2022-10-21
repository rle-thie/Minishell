/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:36:19 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/21 18:43:30 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//je vais avoir besoin du nombre de cmds
void	parent_process(char **av)
{
	char 	*avs[] = {"ls", NULL };
	t_fd	*pipe_fd;
	int		i;

	pipe_fd = open_pipes(av);
	i = 0;
	while (pipe_fd[i].fd[0] != -1)
	{
		exec("ls", avs, pipe_fd);
		i++;
	}
	close_pipes(pipe_fd);
}

void	child_process()
{
	int	ret;
	
	if (pipe_write)
		dup2()
	close_pipes(fds);
	ret = execve(path(str), args, g_data.env);
	exit(ret);
}

void	exec(char *str, char **args, t_fd *fds)
{
	int	pid;

	(void)str;
	(void)args;

	struct_to_char();
	pid = fork();
	if (pid == -1)
	{
		perror("bash :");
		return ;
	}
	if (pid == 0)
		child_process();
	wait(NULL);
}

t_fd	*open_pipes(char **av)
{
	t_fd	*pipe_fd;
	int		size;
	int		i;

	//size = cmd_number(); quand on join nos parties on fera ça
	size = nb_pipes(av);
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

int	close_pipes(t_fd	*pipe_fd)
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

int	nb_pipes(char **str)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	k = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '|')
				k++;
			j++;
		}
		i++;
	}
	return (k);
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

