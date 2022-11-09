/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_multiple_quote.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:17:02 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/06 15:17:13 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*check_multiple_quote_utils(t_token *cmd, char *tab)
{
	if (cmd && cmd->type == QUOTE && ft_strlen(cmd->str) % 2 == 0)
		cmd = delete_lst(cmd);
	else if (cmd && cmd->type == QUOTE && ft_strlen(cmd->str) % 2 == 1)
	{
		if (ft_strlen(cmd->str) != 1)
			cmd->str = ft_strdup_gc(tab, &g_data);
	}
	return (cmd);
}

t_token	*check_multiple_dquote_utils(t_token *cmd, char *tab)
{
	if (cmd && cmd->type == DQUOTE && ft_strlen(cmd->str) % 2 == 0)
		cmd = delete_lst(cmd);
	else if (cmd && cmd->type == DQUOTE && ft_strlen(cmd->str) % 2 == 1)
	{
		if (ft_strlen(cmd->str) != 1)
			cmd->str = ft_strdup_gc(tab, &g_data);
	}
	return (cmd);
}

t_token	*check_multiple_quote(t_token *cmd)
{
	char *tab;

	tab = NULL;
	tab = ft_calloc(sizeof(char) * 2, &g_data);
	tab[0] = '\'';
	while (cmd && cmd->next)
	{
		if (cmd && cmd->type == QUOTE && ft_strlen(cmd->str) % 2 == 0)
			cmd = delete_lst(cmd);
		else if (cmd && cmd->type == QUOTE && ft_strlen(cmd->str) % 2 == 1)
		{
			if (ft_strlen(cmd->str) != 1)
				cmd->str = ft_strdup_gc(tab, &g_data);
		}
		cmd = cmd->next;
	}
	if (cmd)
		cmd = check_multiple_quote_utils(cmd, tab);
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	ft_free(tab, &g_data);
	return (cmd);
}

t_token	*check_multiple_dquote(t_token *cmd)
{
	char *tab;

	tab = NULL;
	tab = ft_calloc(sizeof(char) * 2, &g_data);
	tab[0] = '"';
	while (cmd && cmd->next)
	{
		if (cmd && cmd->type == DQUOTE && ft_strlen(cmd->str) % 2 == 0)
			cmd = delete_lst(cmd);
		else if (cmd && cmd->type == DQUOTE && ft_strlen(cmd->str) % 2 == 1)
		{
			if (ft_strlen(cmd->str) != 1)
				cmd->str = ft_strdup_gc(tab, &g_data);
		}
		cmd = cmd->next;
	}
	if (cmd)
		cmd = check_multiple_dquote_utils(cmd, tab);
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	ft_free(tab, &g_data);
	return (cmd);
}

t_token	*check_multiple_allquote(t_token *cmd)
{
	cmd = check_multiple_quote(cmd);
	cmd = check_multiple_dquote(cmd);
	return (cmd);
}