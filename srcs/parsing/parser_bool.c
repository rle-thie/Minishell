/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:04:07 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/24 11:09:38 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	add_pipe(t_cmd	*cmd)
{
	while (cmd->next)
	{
		cmd->pipe_out = 1;
		if (cmd->prev)
			cmd->pipe_in = 1;
		cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->prev)
			cmd->pipe_in = 1;
	}
}

void	init_index(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->next)
	{
		cmd->index = i;
		i++;
		cmd = cmd->next;
	}
	if (cmd)
	{
		cmd->index = i;
	}
}

void	add_bool_var(t_cmd *format_cmd)
{
	if (!format_cmd->cmd_name)
	{
		format_cmd->cmd_name = ft_calloc(sizeof(char) * 1, &g_data);
		g_data.formated_cmd->bool_cmd = 0;
	}
	else
		g_data.formated_cmd->bool_cmd = 1;
	init_index(format_cmd);
	add_pipe(format_cmd);
}
