/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:11:57 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/21 18:11:47 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int		strlen_exept(char *str, char exept)
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

char	*delete_tiret(char *str)
{
	char	*str2;
	int		i;
	int		y;

	y = 0;
	i = 0;
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

char	*fill_flags(t_token *cmd)
{
	char	*flags;

	flags = ft_calloc(sizeof(char) * 500, &g_data);
	if (!cmd)
		return (NULL);
	while(cmd->next && cmd->type != PIPE)
	{
		if (cmd->type == WORD && cmd->str[0] != '-')
			break;
		if (cmd->type == WORD && cmd->str[0] == '-')
			flags = ft_strjoin_gc(flags, cmd->str, &g_data);
		cmd = cmd->next;
	}
	if (cmd)
	{
		if (cmd->type == WORD && cmd->str[0] == '-')
			flags = ft_strjoin_gc(flags, cmd->str, &g_data);
	}
	printf("'%s'\n", delete_tiret(flags));
	flags = delete_tiret(flags);
	// flags = 
	// return (flags);
}