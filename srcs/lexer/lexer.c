/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:00:12 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 02:25:52 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token_type	choose_type_char(char ch)
{
	t_token_type	type;

	if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r')
		type = WHITE_SPACE;
	else if (ch == PIPE)
		type = PIPE;
	else if (ch == DQUOTE)
		type = DQUOTE;
	else if (ch == QUOTE)
		type = QUOTE;
	else if (ch == REDIR_IN)
		type = REDIR;
	else if (ch == REDIR_OUT)
		type = REDIR;
	else if (ch == DOLLAR)
		type = DOLLAR;
	else
		type = LETTER;
	return (type);
}

t_token	*ft_create_lst_token(t_data *data, char ch)
{
	t_token	*new;

	new = ft_malloc(sizeof(t_token), data);
	new->next = NULL;
	new->prev = NULL;
	new->c = '\0';
	new->c = ch;
	new->type = choose_type_char(new->c);
	return (new);
}

void	lexer(char *str, t_data *data)
{
	t_token	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		if (!data->token)
		{
			data->token = ft_create_lst_token(data, str[i]);
			tmp = data->token;
		}
		else
		{
			data->token->next = ft_create_lst_token(data, str[i]);
			data->token->next->prev = data->token;
			data->token = data->token->next;
		}
		i++;
	}
	if (i <= 0)
		return ;
	create_cmd(data->cmd, tmp, data, i);
	lexer_space(data->cmd);
	data->cmd = check_quote(data->cmd);
	data->cmd = check_variable_env(data->cmd);
}
