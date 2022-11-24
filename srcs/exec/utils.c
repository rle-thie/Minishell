/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:31:54 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/24 12:18:55 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
	int		i;
	t_redir	*head;

	i = 0;
	printf("cmd name : %s\n", cmd->cmd_name);
	i = 0;
	while (cmd->flags_and_args[i])
	{
		printf("cmd args : %s\n", cmd->flags_and_args[i]);
		i++;
	}
	head = cmd->redir;
	while (head)
	{
		printf("name : %s, type %d", head->file_name, head->type);
		head = head->next;
	}
}

void	print_pipes(t_fd *pipe_fd)
{
	int	i;

	i = 0;
	while (pipe_fd[i].fd[0] != -1)
	{
		printf("%d %d\n", pipe_fd[i].fd[0], pipe_fd[i].fd[1]);
		i++;
	}
}

t_cmd	*get_last_cmd(void)
{
	t_cmd	*head;

	head = g_data.formated_cmd;
	while (head)
	{
		if (head->next == NULL)
			return (head);
		head = head->next;
	}
	return (head);
}

void	check_cmd_bool(t_cmd *cmd)
{
	if (!cmd->bool_cmd)
		exit(0);
}
