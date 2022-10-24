/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:11:57 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/23 17:21:02 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	strlen_exept(char *str, char exept)
{
	int		len;
	int		i;

	len = 1;
	i = 0;
	while (str[i])
	{
		if (str[i++] != exept)
			len++;
	}
	return (len);
}

int	only_tiret(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

char	*delete_tirets(char *str)
{
	char	*str2;
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (!str || only_tiret(str) == 1)
		return (NULL);
	str2 = ft_calloc(sizeof(char) * strlen_exept(str, '-'), &g_data);
	while (str[i])
	{
		if (str[i] != '-')
		{
			str2[y] = str[i];
			y++;
		}
		i++;
	}
	return (str2);
}

int	check_flags(t_token *cmd)
{
	int	i;

	i = 0;
	while (cmd->next && cmd->type != PIPE)
	{
		if (cmd->type == WORD && cmd->str[0] != '-')
			break ;
		if (cmd->type == WORD && cmd->str[0] == '-')
			i++;
		cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == WORD && cmd->str[0] == '-')
			i++;
	}
	if (i == 0)
		return (0);
	else
		return (i);
}

char	*fill_flags(t_token *cmd)
{
	char	*flags;

	if (!cmd)
		return (NULL);
	flags = NULL;
	if (check_flags(cmd) != 0)
		flags = ft_calloc(sizeof(char) * 500, &g_data);
	while (cmd->next && cmd->type != PIPE)
	{
		if (cmd->type == WORD && cmd->str[0] != '-')
			break ;
		if (cmd->type == WORD && cmd->str[0] == '-')
			flags = ft_strjoin_gc(flags, cmd->str, &g_data);
		cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == WORD && cmd->str[0] == '-')
			flags = ft_strjoin_gc(flags, cmd->str, &g_data);
	}
	flags = delete_tirets(flags);
	flags = put_tiret(flags);
	return (flags);
}
