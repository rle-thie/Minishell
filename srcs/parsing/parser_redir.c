/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:46 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/12 16:54:25 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	select_redir(t_token *cmd)
{
	while (cmd->next && cmd->next->type != PIPE && cmd && cmd->type != PIPE)
	{
		if (cmd->type == REDIR)
		{
			if (cmd->next)
				cmd = cmd->next;
			while ((cmd->type == WHITE_SPACE || cmd->type == REDIR) && cmd->next)
			{
				cmd->type = cmd->prev->type;
				cmd = cmd->next;
			}
			if (cmd->type == PIPE)
				break ;
			cmd->type = cmd->prev->type;
			// printf("'%s'\n", cmd->str);

		}
		if (cmd->next)
			cmd = cmd->next;
	}
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

int	is_redir(t_token *cmd)
{
	while (cmd->next && cmd->next->type != PIPE)
	{
		if (cmd->type == REDIR)
			return (1);
		cmd = cmd->next;
	}
	if (cmd && cmd->type == REDIR)
		return (1);
	return (0);
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

	select_redir(cmd);
	redir_lst = join_redir(cmd);
	if (redir_lst)
		redir_lst = lst_put_start(redir_lst);
	delete_redir_type(cmd);
	delete_redir_type(cmd);
	// ft_print_token(cmd);
	// printf("fin\n");
	redir_lst = format_redir_lst(redir_lst);
	if (redir_lst)
		redir_lst = clean_all_redir(redir_lst);
	redir_lst = delete_chevron(redir_lst);
	redir_lst = check_heredoc(redir_lst);

	while (redir_lst && redir_lst->next)
	{
		printf("'%s'\n", redir_lst->file_name);
		redir_lst = redir_lst->next;
	}
	if (redir_lst)
		printf("'%s'\n", redir_lst->file_name);
	
	while (redir_lst && redir_lst->prev)
		redir_lst = redir_lst->prev;
	return (redir_lst);
}