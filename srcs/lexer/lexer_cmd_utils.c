/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 23:17:53 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/11 10:05:17 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token_type	select_type(char c)
{
	// printf("%c\n", c);
	if (c == '|')
		return (PIPE);
	else if (c == ' ')
		return (WHITE_SPACE);
	else if (c == '>')
		return (REDIR);
	else if (c == '<')
		return (REDIR);
	// else if (c == IN_DQUOTE)
	// 	return (IN_DQUOTE);
	// else if (c == IN_QUOTE)
	// 	return (IN_QUOTE);
	else if (c == '$')
		return (DOLLAR);
	else if (c == '"')
		return (DQUOTE);
	else if (c == '\'')
		return (QUOTE);
	else if (ft_isascii(c))
		return (WORD);
	else
		return (JSP);
	
		
}

char	*trans(char c, t_data *data)
{
	char *str;
	str = ft_malloc(sizeof(char)*2, data);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	fill_type(t_token *cmd, t_data *data)
{
	while (cmd->prev)
	{
		cmd->type = select_type(cmd->str[0]);
		cmd = cmd->prev;
	}
	// while (cmd->next)
	// 	cmd = cmd->next;
	if (cmd)
	{
		// printf("%d '%c'\n", cmd->type, cmd->str[0]);
		cmd->type = select_type(cmd->str[0]);
	}
	data->cmd = cmd;
}