/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:46 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/21 12:11:53 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_token	*select_redir_utils(t_token *cmd)
{
	if (cmd && cmd->type == REDIR && (cmd->str[0] == '<' || cmd->str[0] == '>'))
	{
		g_data.error = 1;
		g_data.status = 2;
		printf("Minishell: parse error'\n");
	}
	return (cmd);
}

void	select_redir(t_token *cmd)
{
	while (cmd->next && cmd->next->type != PIPE && cmd && cmd->type != PIPE)
	{
		if (cmd->type == REDIR)
		{
			if (cmd->next)
				cmd = cmd->next;
			while (cmd && cmd->type == REDIR && cmd->next)
			{
				cmd->type = cmd->prev->type;
				cmd = cmd->next;
			}
			while (cmd && cmd->type == WHITE_SPACE && cmd->next)
			{
				cmd->type = cmd->prev->type;
				cmd = cmd->next;
			}
			if (cmd && cmd->type == PIPE)
				break ;
			if (cmd)
				cmd->type = cmd->prev->type;
		}
		if (cmd->next)
			cmd = cmd->next;
	}
	cmd = select_redir_utils(cmd);
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
	return (redir_lst);
}

void	delete_redir_type(t_token *cmd)
{
	while (cmd && cmd->next && cmd->next->type != PIPE && cmd->type != PIPE)
	{
		if (cmd->type == REDIR)
		{
			delete_lst(cmd);
		}
		cmd = cmd->next;
	}
	if (cmd && cmd->type == REDIR)
		delete_lst(cmd);
}

t_redir	*parse_redir(t_token *cmd)
{
	t_redir	*redir_lst;
	int		exits;

	exits = g_data.status;
	select_redir(cmd);
	redir_lst = join_redir(cmd);
	if (redir_lst)
		redir_lst = lst_put_start(redir_lst);
	delete_redir_type(cmd);
	delete_redir_type(cmd);
	if (g_data.error == 0 && is_valid_redir(redir_lst) == 1)
	{
		redir_lst = format_redir_lst(redir_lst);
		if (redir_lst)
			redir_lst = clean_all_redir(redir_lst);
		redir_lst = delete_chevron(redir_lst);
		g_data.status = 0;
		redir_lst = check_heredoc(redir_lst, NULL);
		if (g_data.status != 130)
			g_data.status = exits;
	}
	if (g_data.error != 0)
		sig_handler_heredoc();
	check_redir_error(redir_lst);
	while (redir_lst && redir_lst->prev)
		redir_lst = redir_lst->prev;
	return (redir_lst);
}
