/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 15:00:12 by rle-thie          #+#    #+#             */
/*   Updated: 2022/06/07 04:33:23 by rle-thie         ###   ########.fr       */
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
			data->token = ft_create_lst_token(data, str[i]);
		else
		{
			data->token->next = ft_create_lst_token(data, str[i]);
			data->token->next->prev = data->token;
		}
		i++;
	}
	tmp = data->token;
	tmp=tmp;
	while (tmp->next)
	{
		printf("%c %p %c\n", tmp->c, &tmp->next, tmp->next->c);
		tmp = tmp->next;
	}
	
	// ft_sort_char()
	printf("end func\n");
}