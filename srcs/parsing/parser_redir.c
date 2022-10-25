/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:46 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:47 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	delete_lst(t_cmd *lst)
{
	if (!lst->prev && !lst->next)
		g_data.formated_cmd = NULL;
	else if (!lst->prev)
	{
		*lst = *(lst)->next;
		lst->prev = NULL;
	}
	else if (!lst->next)
	{
		lst = lst->prev;
		lst->next = NULL;
	}
	else if (lst->prev && lst->next)
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
	}
}

void	select_redir(t_token *cmd)
{
	t_token	*tmp;

	tmp = cmd;
	tmp=tmp;
	// if (cmd == NULL)
	// 	return NULL;
	while (cmd->next && cmd->next->type != PIPE)
	{
		if (cmd->type == REDIR_IN || cmd->type == REDIR_OUT)
		{
			if (cmd->next)
				cmd = cmd->next;
			if (cmd->type == WHITE_SPACE && cmd->next)
			{
				cmd->type = cmd->prev->type;
				cmd = cmd->next;
			}
			if (cmd->type == PIPE)
				break ;
			
			cmd->type = cmd->prev->type;
			printf("'%s'\n", cmd->str);

		}
		if (cmd->next)
			cmd = cmd->next;
	}
	ft_print_token(tmp);
	// return (cmd);
}