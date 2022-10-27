/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 02:15:47 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/27 02:15:48 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redir	*ft_create_redir(char *str)
{
	t_redir *new;

	new = ft_malloc(sizeof(t_redir), &g_data);
	new->next = NULL;
	new->prev = NULL;
	new->file_name = str;
	new->type = 0;
	// str=str;
	// new->type = type;
	// printf("lst created '%s'\n", str);
	return (new);
}

t_redir	*add_back_redir(t_redir *token, char *str)
{
	t_redir *new;

	new = token;
	if (!token)
	{
		new = ft_create_redir(str);
		// new->str = str;
	}
	else
	{
		new->next = ft_create_redir(str);
		// new->str = str;
		new->next->prev = new;
		new = new->next;
	}
	return (new);
}

t_redir	*lst_put_start(t_redir *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}


t_token	*lst_start_token(t_token *lst)
{
	if (!lst)
		return (NULL);
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}