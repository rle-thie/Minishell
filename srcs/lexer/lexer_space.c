/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:13:36 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/18 22:43:03 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	lexer_space(t_token *cmd)
{
	t_token	*tmp;
	int		i;

	i = 0;
	tmp = cmd;
	if (tmp->next && tmp->type == WHITE_SPACE)
	{
		tmp->next->prev = NULL;
		tmp = tmp->next;
	}
	while (tmp->next)
	{
		if (i++ == 0 && tmp->type == WHITE_SPACE)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		if (tmp->type == PIPE)
			i = 0;
		tmp = tmp->next;
	}
	while (tmp->prev)
		tmp = tmp->prev;
	g_data.cmd = tmp;
	// ft_print_token(g_data.cmd);
}
// je mange du caca | et du pipi