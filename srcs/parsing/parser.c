/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:26:17 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/22 12:10:07 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*create_parser_list(void)
{
	t_cmd	*new;

	new = ft_malloc(sizeof(t_cmd), &g_data);
	new->prev = NULL;
	new->next = NULL;
	new->redir = NULL;
	new->cmd_name = NULL;
	new->flags = NULL;
	new->args = NULL;
	new->nbr_args = 0;
	new->pipe_in = 0;
	new->pipe_out = 0;
	new->bool_redir_in = 0;
	new->bool_redir_out = 0;
	new->index = -1;
	new->pid = -1;
	return (new);
}

void	add_back_parser(void)
{
	if (!g_data.formated_cmd)
		g_data.formated_cmd = create_parser_list();
	else
	{
		g_data.formated_cmd->next = create_parser_list();
		g_data.formated_cmd->next->prev = g_data.formated_cmd;
		g_data.formated_cmd = g_data.formated_cmd->next;
	}
}

char	*select_cmd(t_token *cmd)
{
	char	*str2;

	str2 = NULL;
	while (cmd->next && cmd && cmd->type != PIPE)
	{
		if (cmd->type == WORD)
		{
			str2 = cmd->str;
			delete_lst(cmd);
			return (str2);
		}
		cmd = cmd->next;
	}
	if (cmd && cmd->type == WORD)
	{
		str2 = cmd->str;
		delete_lst(cmd);
		return (str2);
	}
	return (NULL);
}

void	fill_cmd(t_token *cmd)
{
	add_back_parser();
	g_data.formated_cmd->redir = parse_redir(cmd);
	g_data.formated_cmd->cmd_name = select_cmd(cmd);
	if (cmd->next)
	{
		cmd = cmd->next;
		g_data.formated_cmd->flags = fill_flags(cmd);
		g_data.formated_cmd->args = fill_args(cmd);
	}
	g_data.formated_cmd->flags_and_args = fill_flags_args(
			g_data.formated_cmd->flags,
			g_data.formated_cmd->args,
			g_data.formated_cmd->nbr_args,
			g_data.formated_cmd->cmd_name);
}

void	parser(void)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = g_data.cmd;
	if (!g_data.cmd)
		return ;
	while (tmp && tmp->next)
	{
		if (i++ == 0 && tmp)
			fill_cmd(tmp);
		if (tmp && tmp->type == PIPE)
			i = 0;
		if (tmp && tmp->next)
			tmp = tmp->next;
	}
	if (tmp)
	{
		if (i++ == 0 && tmp)
			fill_cmd(tmp);
	}
	while (g_data.formated_cmd->prev)
		g_data.formated_cmd = g_data.formated_cmd->prev;
	add_bool_var(g_data.formated_cmd);
}
