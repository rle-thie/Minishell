/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_checkdouble_dollar.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:49:37 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/09 02:50:04 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*ft_create_token_dollar(t_token_type type)
{
	t_token	*new;
	char	*str;

	str = create_one_char('$');
	new = ft_malloc(sizeof(t_token), &g_data);
	new->next = NULL;
	new->prev = NULL;
	new->type = type;
	new->str = str;
	return (new);
}

t_token	*add_before_token_dollar(t_token *lst, t_token_type type)
{
	t_token	*new;

	new = ft_create_token_dollar(type);
	if (!lst->prev)
	{
		lst->prev = new;
		new->next = lst;
		return (lst);
	}
	else if (lst->prev)
	{
		lst->prev->next = new;
		new->prev = lst->prev;
		lst->prev = new;
		new->next = lst;
		return (lst);
	}
	return (NULL);
}

t_token	*check_double_dollar(t_token *cmd, int i, int len)
{
	while (cmd && cmd->next)
	{
		if (cmd->type == DOLLAR && ft_strlen(cmd->str) > 1)
		{
			len = ft_strlen(cmd->str);
			while (++i < len)
				cmd = add_before_token_dollar(cmd, DOLLAR);
			cmd = delete_lst(cmd);
		}
		if (cmd && cmd->next)
			cmd = cmd->next;
	}
	i = -1;
	if (cmd)
	{
		if (cmd->type == DOLLAR && ft_strlen(cmd->str) > 1)
		{
			len = ft_strlen(cmd->str);
			while (++i < len)
				cmd = add_before_token_dollar(cmd, DOLLAR);
			cmd = delete_lst(cmd);
		}
	}
	return (cmd);
}
