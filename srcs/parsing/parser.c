/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:26:17 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/23 18:59:04 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_cmd	*create_parser_list(void)
{
	t_cmd *new;

	new = ft_malloc(sizeof(t_cmd), &g_data);
	new->prev = NULL;
	new->next = NULL;
	new->cmd_name = NULL;
	new->flags = NULL;
	new->args = NULL;
	new->nbr_args = 0;
	new->pipe_in = 0;
	new->pipe_out = 0;
	new->bool_redir_in = 0;
	new->bool_redir_out = 0;
	new->index = -1;
	// new->c = ch;
	// new->str = NULL;
	// new->type = choose_type_char(new->c);
	// printf("lst created\n");
	return (new);
}

void	add_back_parser(void)
{
	// t_cmd	*tmp;

	if (!g_data.formated_cmd)
	{
		g_data.formated_cmd = create_parser_list();
		// tmp = g_data.cmd;
	}
	else
	{
		g_data.formated_cmd->next = create_parser_list();
		g_data.formated_cmd->next->prev = g_data.formated_cmd;
		g_data.formated_cmd = g_data.formated_cmd->next;
	}
}

void	fill_cmd(t_token *cmd)
{
	// cmd=cmd;
	add_back_parser();
	// ajouter une fction qui fill tout les champs.......
	g_data.formated_cmd->cmd_name = cmd->str;
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
	// ft_print_args(g_data.formated_cmd->flags_and_args);
	// printf("%s\n", g_data.formated_cmd->cmd_name);
}

void	parser(void)
{
	int	i;
	t_token	*tmp;
	
	i = 0;
	tmp = g_data.cmd;
	if (!g_data.cmd)
		return ;
	while (tmp->next)
	{
		if (i++ == 0 && tmp)
			fill_cmd(tmp);
		if (tmp->type == PIPE)
			i = 0;
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
	// printf("%s %s\n", g_data.formated_cmd->prev->cmd_name, g_data.formated_cmd->cmd_name);
	// ft_print_formated(g_data.formated_cmd);
}