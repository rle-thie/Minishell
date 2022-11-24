/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_repalce_allquote.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:17:49 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/08 12:16:42 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// type = INQUOTE ou INDQUOTE
char	*join_inquote(t_token *cmd, t_token_type type)
{
	char	*tab;

	tab = ft_calloc(sizeof(char) * 2, &g_data);
	tab[0] = ' ';
	while (cmd && cmd->next && cmd->type == type)
	{
		tab = ft_strjoin_gc(tab, cmd->str, &g_data);
		cmd = cmd->next;
	}
	if (cmd && cmd->type == type)
	{
		tab = ft_strjoin_gc(tab, cmd->str, &g_data);
	}
	tab = del_first_space(tab);
	if (type == IN_DQUOTE)
		tab = expand_varchar(tab, 0);
	return (tab);
}

t_token	*fill_word_inquote(t_token *cmd)
{
	if (cmd->next && cmd->next->type == IN_QUOTE)
		cmd = cmd->next;
	else
		return (cmd);
	cmd->str = join_inquote(cmd, IN_QUOTE);
	cmd->type = WORD;
	if (cmd->next && cmd->next->type == IN_QUOTE)
		cmd = cmd->next;
	else
		return (cmd);
	while (cmd && cmd->next && cmd->type == IN_QUOTE)
	{
		cmd = delete_lst(cmd);
		cmd = cmd->next;
	}
	if (cmd && cmd->type == IN_QUOTE)
		cmd = delete_lst(cmd);
	return (cmd);
}

t_token	*fill_word_indquote(t_token *cmd)
{
	if (cmd->next && cmd->next->type == IN_DQUOTE)
		cmd = cmd->next;
	else
		return (cmd);
	cmd->str = join_inquote(cmd, IN_DQUOTE);
	cmd->type = WORD;
	if (cmd->next && cmd->next->type == IN_DQUOTE)
		cmd = cmd->next;
	else
		return (cmd);
	while (cmd && cmd->next && cmd->type == IN_DQUOTE)
	{
		cmd = delete_lst(cmd);
		cmd = cmd->next;
	}
	if (cmd && cmd->type == IN_DQUOTE)
		cmd = delete_lst(cmd);
	return (cmd);
}

t_token	*replace_allquote(t_token *cmd)
{
	while (cmd && cmd->next)
	{
		if (cmd->type == QUOTE)
		{
			cmd = fill_word_inquote(cmd);
		}
		else if (cmd->type == DQUOTE)
		{
			cmd = fill_word_indquote(cmd);
		}
		if (cmd->next)
			cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == QUOTE)
			cmd = fill_word_inquote(cmd);
		else if (cmd->type == DQUOTE)
			cmd = fill_word_indquote(cmd);
	}
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}
