/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_variable_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:04:31 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 01:49:55 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*delete_double_space(t_token *cmd)
{
	while (cmd && cmd->next)
	{
		while (cmd && cmd->next && cmd->type == WHITE_SPACE && cmd->next->type == WHITE_SPACE)
		{
			cmd = delete_lst_tok(cmd);
		}
		if (cmd && cmd->next)
			cmd = cmd->next;
	}
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}

t_token	*delete_all_dollar(t_token *cmd)
{
	while (cmd && cmd->next)
	{
		if (cmd->type == DOLLAR || cmd->type == FT_ERROR)
		{
			cmd = delete_lst_tok(cmd);
		}
		else if (cmd->next)
			cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == DOLLAR || cmd->type == FT_ERROR)
		{
			cmd = delete_lst_tok(cmd);
		}
	}
	// ft_print_token(cmd);
	while (cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}

t_token	*dollar_to_word_type(t_token *cmd)
{
	while (cmd && cmd->next)
	{
		if (!cmd->next || (cmd && cmd->type == DOLLAR && cmd->next && cmd->next->type != WORD))
			cmd->type = WORD;
		cmd = cmd->next;
	}
	if (cmd)
	{
		if ((!cmd->next && cmd->type == DOLLAR)|| (cmd && cmd->type == DOLLAR && cmd->next && cmd->next->type != WORD))
			cmd->type = WORD;
	}
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}

t_token	*check_variable_env(t_token *cmd)
{
	cmd = check_double_dollar(cmd, -1, 0);
	while (cmd->prev)
		cmd = cmd->prev;
	cmd = dollar_to_word_type(cmd);
	cmd = expand_var(cmd);
	cmd = delete_all_dollar(cmd);
	cmd = delete_double_space(cmd);
	while (cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}