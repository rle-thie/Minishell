/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_putin_allquote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:11:12 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/06 16:11:35 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token *putin_quote(t_token *cmd)
{
	if (cmd->next)
		cmd = cmd->next;
	while (cmd && cmd->next && cmd->type != QUOTE)
	{
		cmd->type = IN_QUOTE;
		cmd = cmd->next;
	}
	if (cmd && cmd->type != QUOTE)
	{
		cmd->type = IN_QUOTE;
	}
	return (cmd);
	
}

t_token *putin_dquote(t_token *cmd)
{
	if (cmd->next)
		cmd = cmd->next;
	while (cmd && cmd->next && cmd->type != DQUOTE)
	{
		cmd->type = IN_DQUOTE;
		cmd = cmd->next;
	}
	if (cmd && cmd->type != DQUOTE)
	{
		cmd->type = IN_DQUOTE;
	}
	return (cmd);
	
}

t_token *putin_allquote(t_token *cmd)
{
	while (cmd && cmd->next)
	{
		if (cmd && cmd->type == QUOTE)
			cmd = putin_quote(cmd);
		else if (cmd && cmd->type == DQUOTE)
			cmd = putin_dquote(cmd);
		if (cmd->next)
			cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd && cmd->type == QUOTE)
			cmd = putin_quote(cmd);
		else if (cmd && cmd->type == DQUOTE)
			cmd = putin_dquote(cmd);
	}
	while (cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}