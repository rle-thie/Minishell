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

void	delete_lst(t_token *lst)
{
	if (!lst->prev && !lst->next)
		g_data.cmd = NULL;
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
	while (cmd->next && cmd->next->type != PIPE && cmd && cmd->type != PIPE)
	{
		if (cmd->type == REDIR)
		{
			if (cmd->next)
				cmd = cmd->next;
			if (cmd->type == WHITE_SPACE && cmd->next)
			{
				cmd->type = cmd->prev->type;
				cmd = cmd->next;
			}
			if (cmd->type == PIPE)
			{
				break ;
			}
			cmd->type = cmd->prev->type;
			// printf("'%s'\n", cmd->str);

		}
		if (cmd->next)
			cmd = cmd->next;
	}
}

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

t_redir	*join_redir(t_token *cmd)
{
	t_redir	*redir_lst;
	char	*str;

	redir_lst = NULL;
	while (cmd->next && cmd->next->type != PIPE && cmd && cmd->type != PIPE)
	{
		str = ft_calloc(sizeof(char) * 2, &g_data);
		str[0] = ' ';
		while (cmd->next && cmd->type == REDIR && cmd->next->type != PIPE)
		{
			str = ft_strjoin_gc(str, cmd->str, &g_data);
			cmd = cmd->next;
		}
		if (cmd && cmd->type == REDIR)
			str = ft_strjoin_gc(str, cmd->str, &g_data);
		if (ft_strlen(str) >= 2)
			redir_lst = add_back_redir(redir_lst, ft_strdup_gc(str, &g_data));
		if (cmd->next)
			cmd = cmd->next;
		ft_free(str, &g_data);
	}
	// printf("fin\n");
	return (redir_lst);
}

t_redir	*lst_put_start(t_redir *lst)
{
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}

void	delete_redir_type(t_token *cmd)
{
	t_token	*tmp;

	tmp = cmd;
	while (tmp->next && tmp && tmp->type != PIPE)
	{
		if (tmp->type == REDIR)
		{
			printf("delete '%s'\n", tmp->str);
			delete_lst(tmp);
			tmp = cmd;
		}
		else
			tmp = tmp->next;
	}
	if (tmp && tmp->type == REDIR)
	{
		printf("delete '%s'\n", tmp->str);
		delete_lst(tmp);
	}
}

t_redir	*parse_redir(t_token *cmd)
{
	t_redir	*redir_lst;

	select_redir(cmd);
	redir_lst = join_redir(cmd);
	if (redir_lst)
		redir_lst = lst_put_start(redir_lst);
	// parser les redirection colle genre ">1>2"

	delete_redir_type(cmd);
	printf("fin\n");
	return (redir_lst);
}