/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:00:12 by rle-thie          #+#    #+#             */
/*   Updated: 2022/05/30 19:59:21 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// creer new_token();
t_token	*new_token(char c, t_data *data)
{
	t_token	*new;

	new = ft_malloc(sizeof(t_token), data);
	new->c = c;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// void	add_token_lst(char c, t_data)
// {
// 	if (!data->token)
// 	{
// 		// new token tout ca
// 		data->token = ft_malloc(sizeof(t_token), data);
// 		data->token->prev = NULL;
// 		data->token->next = NULL;
// 		data->token->content = c;
// 		data->token->type = type_char(c, token_type);
// 	}
// 	else
// 	{
// 		while (data->token->next)
// 			data->token = data->token->next;
// 		data->token->next = new_token();
// 		data->token->next->prev = data->token;
// 		data->token = data->token->next;
		
// 	}
// }

void	create_token(char *str, t_data *data)
{
	int	i;

	i = 0;
	str=str;
	data=data;
	while (str[i])
	{
		new_token(str[i], data);
		i++;
	}
	
}