/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:00:12 by rle-thie          #+#    #+#             */
/*   Updated: 2022/06/07 05:05:07 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*ft_create_lst_token(t_data *data, char ch)
{
	t_token *new;

	new = ft_malloc(sizeof(t_token), data);
	new->next = NULL;
	new->prev = NULL;
	new->c = ch;
	printf("lst created '%c'\n", new->c);
	return (new);
}

void	ft_lst_token_add(t_data *data, char ch)
{
	data->token->next = ft_create_lst_token(data, ch);
}

void	lexer(char *str, t_data *data)
{
	int i;
	t_token *tmp;

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
	
	while (tmp->next)
	{
		printf("prev=%p, current=%c, next=%p\n", tmp->prev, tmp->c, tmp->next);
		tmp = tmp->next;
	}
	printf("prev=%p, current=%c, next=%p\n", tmp->prev, tmp->c, tmp->next);

	// ft_sort_char()
	// printf("end func\n");
}