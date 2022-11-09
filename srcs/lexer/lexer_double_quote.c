/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_double_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:06:14 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/09 00:47:25 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*create_one_char(char c)
{
	char	*str;

	str = ft_calloc(sizeof(char) * 2, &g_data);
	str[0] = c;
	return (str);
}

t_token	*ft_create_token(t_token_type type)
{
	char	*str;

	if (type == QUOTE)
		str = create_one_char('\'');
	else if (type == DQUOTE)
		str = create_one_char('\"');
	t_token *new;
	new = ft_malloc(sizeof(t_token), &g_data);
	new->next = NULL;
	new->prev = NULL;
	new->type = type;
	new->str = str;
	return (new);
}

t_token	*add_before_token(t_token *lst, t_token_type type)
{
	t_token	*new;

	new = ft_create_token(type);
	if (!lst->prev)
	{
		lst->prev = new;
		new->next = lst;
		// lst = lst->prev;
		return (lst);
	}
	else if (lst->prev)
	{
		lst->prev->next = new;
		new->prev = lst->prev;
		lst->prev = new;
		new->next = lst;
		// lst = lst->prev;
		return (lst);
	}
	return (NULL);
}


t_token	*check_double_quote(t_token *cmd, int i, int len)
{
	while (cmd && cmd->next)
	{
		if (cmd->type == QUOTE && ft_strlen(cmd->str) > 1)
		{
			len = ft_strlen(cmd->str);
			while(++i < len)
				cmd = add_before_token(cmd, QUOTE);
			cmd = delete_lst(cmd);
		}
		if (cmd && cmd->next)
			cmd = cmd->next;
	}
	i = -1;
	if (cmd)
	{
		if (cmd->type == QUOTE && ft_strlen(cmd->str) > 1)
		{
			len = ft_strlen(cmd->str);
			while(++i < len)
				cmd = add_before_token(cmd, QUOTE);
			cmd = delete_lst(cmd);
		}
		// if (cmd && cmd->next)
		// 	cmd = cmd->next;
	}
	return (cmd);
}

t_token	*check_double_dquote(t_token *cmd, int i, int len)
{
	while (cmd && cmd->next)
	{
		if (cmd->type == DQUOTE && ft_strlen(cmd->str) > 1)
		{
			len = ft_strlen(cmd->str);
			while(++i < len)
				cmd = add_before_token(cmd, DQUOTE);
			cmd = delete_lst(cmd);
		}
		if (cmd && cmd->next)
			cmd = cmd->next;
	}
	i = -1;
	if (cmd)
	{
		if (cmd->type == DQUOTE && ft_strlen(cmd->str) > 1)
		{
			len = ft_strlen(cmd->str);
			while(++i < len)
				cmd = add_before_token(cmd, DQUOTE);
			cmd = delete_lst(cmd);
		}
		// if (cmd && cmd->next)
		// 	cmd = cmd->next;
	}
	return (cmd);
}

t_token	*check_double_allquote(t_token *cmd)
{
	cmd = check_double_quote(cmd, -1, 0);
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	cmd = check_double_dquote(cmd, -1, 0);
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}