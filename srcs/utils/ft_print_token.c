/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:27:28 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/01 01:29:03 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_print_token(t_token *token)
{
	while (token->next)
	{
		printf("%p %p [%s] %d %p\n", token->prev, token, token->str, token->type, token->next);
		token = token->next;
	}
	if (token)
		printf("%p %p [%s] %d %p\n", token->prev, token, token->str, token->type, token->next);
}