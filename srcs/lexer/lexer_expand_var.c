/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand_var.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:57:19 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 01:40:17 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_env	*find_env_var(char *str)
{
	t_env	*head;

	head = g_data.env_head;
	while (head->next)
	{
		if (!ft_strncmp(head->name, str, ft_strlen(str)))
			return (head);
		head = head->next;
	}
	if (head)
		if (!ft_strncmp(head->name, str, ft_strlen(str)))
			return (head);
	return (NULL);
}

// virer cmd ($) et remplacer cmd.next.str par la valeur de la variable d'env
char	*add_expand(char *var_name)
{
	t_env	*lst;

	lst = find_env_var(var_name);
	var_name = lst->str;
	return (var_name);
}

// est ce que c'est une variable qui existe ?
int	is_envvar(char *str)
{
	if (!find_env_var(str))
		return (0);
	else
		return (1);
	return (1);
}

t_token	*expand_var(t_token *cmd)
{
	while (cmd && cmd->next)
	{
		if (cmd->type == DOLLAR)
		{
			if (cmd->next->str[0] == '?')
			{
				cmd->next->str = expand_status(cmd->next->str);
			}
			else if (is_envvar(cmd->next->str) == 1)
			{
				cmd->next->str = add_expand(cmd->next->str);
			}
			else if (is_envvar(cmd->next->str) == 0)
			{
				cmd->next->type = FT_ERROR;
			}
		}
		cmd = cmd->next;
	}
	while (cmd && cmd->prev)
		cmd = cmd->prev;
	return (cmd);
}
