/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:28:12 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/09 15:30:17 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
