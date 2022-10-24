/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:27:28 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/20 22:28:05 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_print_token(t_token *token)
{
	printf("-----CMD-----\n");
	while (token->next)
	{
		printf("%p %p [%s] %d %p\n", token->prev, token, token->str, token->type, token->next);
		token = token->next;
	}
	if (token)
		printf("%p %p [%s] %d %p\n", token->prev, token, token->str, token->type, token->next);
}

void	ft_print_formated(t_cmd *token)
{
	printf("-----FORMATED_CMD-----\n");
	while (token && token->next)
	{
		printf("%p %p [%s] [%s] [%s] [%s] %p\n", token->prev, token, token->cmd_name, token->flags, token->args[0], token->args[1], token->next);
		token = token->next;
	}
	if (token)
		printf("%p %p [%s] [%s] [%s] [%s] %p\n", token->prev, token, token->cmd_name, token->flags, token->args[0], token->args[1], token->next);
}

void	ft_print_args(char **str)
{
	int i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != NULL)
	{
		printf("'%s' ", str[i++]);
	}
	printf("\n");
}

void print_bool(t_cmd *cmd)
{
	while (cmd->next)
	{
		printf("id:%d\nredir_in:%d\nredir_out:%d\npipe_in:%d\npipe_out:%d\n",
		cmd->index,
		cmd->bool_redir_in,
		cmd->bool_redir_out,
		cmd->pipe_in,
		cmd->pipe_out);
		printf("\n");
		cmd = cmd->next;
	}
	if (cmd)
	{
		printf("id:%d\nredir_in:%d\nredir_out:%d\npipe_in:%d\npipe_out:%d\n",
		cmd->index,
		cmd->bool_redir_in,
		cmd->bool_redir_out,
		cmd->pipe_in,
		cmd->pipe_out);
		printf("\n");
	}
}