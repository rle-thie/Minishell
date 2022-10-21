/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:34:44 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/20 14:35:43 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*find_first_arg(t_token *cmd)
{
	while (cmd->next && cmd->next->type != PIPE && cmd->type != PIPE)
	{
		if (cmd->type == WORD && cmd->str[0] != '-')
			return (cmd);
		cmd = cmd->next;
	}
	if (cmd && cmd->type != PIPE && cmd->type == WORD && cmd->str[0] != '-')
		return (cmd);
	return (NULL);
}

int	len_args(t_token *cmd)
{
	int	i;

	i = 0;
	while (cmd && cmd->next && cmd->next->type != PIPE && cmd->type != PIPE)
	{
		if (cmd->type == WORD && cmd->str[0] != '-')
			i++;
		cmd = cmd->next;
	}
	if (cmd && cmd->type != PIPE && cmd->type == WORD && cmd->str[0] != '-')
		i++;
	return (i);
}

char **create_args(t_token *cmd, int len_args)
{
	char **args;
	int		i;
	
	i = 0;
	args = ft_calloc(sizeof(char *) * (len_args + 1), &g_data);
	while (cmd && cmd->type != PIPE && cmd->next && cmd->next->type != PIPE)
	{
		if (cmd->type == WORD && cmd->str[0] != '-')
		{
			args[i++] = cmd->str;
			// printf("'%s'\n", cmd->str);
		}
		cmd = cmd->next;
	}
	if (cmd && cmd->type != PIPE)
	{
		if (cmd->type == WORD && cmd->str[0] != '-')
		{
			args[i++] = cmd->str;
			// printf("'%s'\n", cmd->str);
		}
	}
	// printf("fin\n");
	if (i == 0)
		return (NULL);
	return (args);
}

// char **merge_args(char **args1, char **args2)
// {
// 	int	i;
// 	int y;
// 	char **final_args;

// 	if (!args1)
// 		return (args2);
// 	i = 0;
// 	y = 0;
// 	final_args = ft_calloc(sizeof(char *)* (lstlen(args2) + lstlen(args1) + 1), &g_data);
// 	while (args1[y])
// 	{
// 		final_args[i++] = args1[y++];
// 	}
// 	y = 0;
// 	while (args2[y])
// 	{
// 		final_args[i++] = args1[y++];
// 	}
// 	return (final_args);
// }


char	**fill_args(t_token *cmd)
{
	char	**args;
	
	cmd = find_first_arg(cmd);
	g_data.formated_cmd->nbr_args = len_args(cmd);
	if (len_args(cmd) < 1)
		return (NULL);
	args = create_args(cmd, len_args(cmd));
	// ft_print_args(args);

	return (args);
}