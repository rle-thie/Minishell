/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:14:35 by rle-thie          #+#    #+#             */
/*   Updated: 2022/06/11 03:45:08 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_token	*ft_create_lst_token(t_data *data)
{
	t_token *new;

	new = ft_malloc(sizeof(t_token), data);
	new->next = NULL;
	new->prev = NULL;
	// printf("lst created '%c' %d\n", new->c, new->type);
	return (new);
}

t_token	*ft_cmd_add(t_token *token, t_data *data)
{
	t_token *new;

	new = token;
	if (!token)
	{
		new = ft_create_lst_token(data);
	}
	else
	{
		new->next = ft_create_lst_token(data);
		new->next->prev = new;
		new = new->next;
	}
	return (new);
}

void	create_cmd(t_token *cmd, t_token *token, t_data *data)
{
	char *str;

	// str = "";
	// str = ft_strjoin_gc(str, ".oui", data);
	// printf("\n\n--%s--\n\n", str);
	cmd=cmd;
	data=data;
	while (token->next)
	{
		str = "";
		while (token->type == WHITE_SPACE && token->next)
			token = token->next;
		
		while (token->type == LETTER && token->next)
		{
			printf("%c", token->c);
			token = token->next;
		}
		printf("%s\n", str);
		if (token->next)
		{
			printf("\n");
			token = token->next;
		}
	}
	if (token && token->type == LETTER)
	{
		printf("%c\n", token->c);
	}
	
}



// void	create_cmd(t_token *token, t_data *data)