/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:14:35 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/01 23:25:03 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_token	*ft_create_lst_cmd(t_data *data, char *str)
{
	t_token *new;

	new = ft_malloc(sizeof(t_token), data);
	new->next = NULL;
	new->prev = NULL;
	new->str = str;
	// str=str;
	// new->type = type;

	
	// printf("lst created '%s'\n", new->str);
	return (new);
}

t_token	*ft_cmd_add(t_token *token, t_data *data, char *str)
{
	t_token *new;

	new = token;
	if (!token)
	{
		new = ft_create_lst_cmd(data, str);
		// new->str = str;
	}
	else
	{
		new->next = ft_create_lst_cmd(data, str);
		// new->str = str;
		new->next->prev = new;
		new = new->next;
	}
	return (new);
}

void	create_cmd_ok(t_token *cmd, t_token *token, t_data *data)
{
	char *str;
	t_token_type type;

	while (token->next)
	{
		type = token->type;
		str = ft_calloc(9999, data);
		if (token->next && token->type == type)
		{
			while (token->next && token->type == type)
			{
				str = ft_strjoin_gc(str, trans(token->c, data), data);
				token = token->next;
			}
		}
		else
			token = token->next;
		cmd = ft_cmd_add(cmd, data, str);
		if(token && !token->next && token->type == type)
			cmd->str = ft_strjoin_gc(cmd->str, trans(token->c, data), data);
		else if (token && !token->next && token->type != type)
			cmd = ft_cmd_add(cmd, data, trans(token->c, data));
		fill_type(cmd, data);
	}
}

void	create_cmd(t_token *cmd, t_token *token, t_data *data, int len)
{
	if (len == 1)
	{
		cmd = ft_cmd_add(cmd, data, trans(token->c, data));
		cmd->type = select_type(cmd->str[0]);
		data->cmd = cmd;
	}
	else
	{
		create_cmd_ok(cmd, token, data);
	}
}

// void	create_cmd(t_token *token, t_data *data)