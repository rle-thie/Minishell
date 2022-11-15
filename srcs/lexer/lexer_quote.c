/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:28:34 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 00:35:42 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*delete_all_quote(t_token *cmd)
{
	while (cmd && cmd->next)
	{
		if (cmd->type == QUOTE || cmd->type == DQUOTE)
		{
			cmd = delete_lst_tok(cmd);
		}
		else if (cmd->next)
			cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == QUOTE || cmd->type == DQUOTE)
		{
			cmd = delete_lst_tok(cmd);
		}
	}
	// ft_print_token(cmd);
	return (cmd);
}

int	check_open_quote(t_token *cmd)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (cmd->next)
	{
		if (cmd->type == QUOTE)
			i++;
		else if (cmd->type == DQUOTE)
			y++;
		cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == QUOTE)
			i++;
		else if (cmd->type == DQUOTE)
			y++;
	}
	if (i % 2 != 0)
		return (-1);
	else if (y % 2 != 0)
		return (-2);
	return (1); 
}

// check_quote(data->cmd);
t_token	*check_quote(t_token *cmd)
{
	int	error;

	error = 0;
	// ft_print_token(cmd);
	cmd = check_double_allquote(cmd);
	cmd = putin_allquote(cmd);
	// cmd = check_multiple_allquote(cmd);
	if (cmd)
	{
		error = check_open_quote(cmd);
		if (error == -1)
			ft_exit_provisoire("minishell: syntax error near unexpected token `\''\n", 0);
		else if (error == -2)
			ft_exit_provisoire("minishell: syntax error near unexpected token `\"'\n", 0);
	}
	if (g_data.error == 1)
		return (NULL);
	cmd = replace_allquote(cmd);
	cmd = delete_all_quote(cmd);

	while (cmd && cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}