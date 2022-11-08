/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:28:34 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/08 12:21:48 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*delete_all_quote(t_token *cmd)
{
	while (cmd && cmd->next)
	{
		if (cmd->type == QUOTE || cmd->type == DQUOTE)
			cmd = delete_lst(cmd);
		if (cmd && cmd->next)
			cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == QUOTE || cmd->type == DQUOTE)
			cmd = delete_lst(cmd);
	}
	if (cmd && cmd->prev)
	cmd = cmd->prev;
	return (cmd);
}

int	check_open_quote(t_token *cmd)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (cmd->next)
	{
		if (cmd->type == QUOTE)
			i++;
		else if (cmd->type == DQUOTE)
			y++;
		cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == QUOTE)
			i++;
		else if (cmd->type == DQUOTE)
			y++;
	}
	if (i % 2 != 0 || y % 2 != 0)
		return (0);
	return (1); 
}

// check_quote(data->cmd);
t_token	*check_quote(t_token *cmd)
{
	cmd = putin_allquote(cmd);
	cmd = check_multiple_allquote(cmd);
	if (cmd && !check_open_quote(cmd))
		ft_exit_provisoire("quote ouvert\n", 2);
	cmd = replace_allquote(cmd);
	cmd = delete_all_quote(cmd);
	// while (cmd && cmd->next)
	// {
	// 	if (cmd->type == QUOTE)
	// 		cmd = lex_quote(cmd);
	// 	if (cmd->next)
	// 		cmd = cmd->next;
	// }
	// if (cmd)
	// {
	// 	if (cmd->type == QUOTE)
	// 		cmd = lex_quote(cmd);
	// }
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	// // ft_printstr("cxacacacacan\n");
	// join_quote(cmd, NULL);
	return (cmd);
}