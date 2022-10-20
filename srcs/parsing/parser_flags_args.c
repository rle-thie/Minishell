/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:21:21 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/20 23:39:03 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_flags(char *flags)
{
	int	i;

	i = 0;
	if (!flags)
		return (0);
	else
		return (1);
	// printf("%d flags\n");
	return (i);
}

char	**fill_flags_args(char *flags, char **args, int nbr_args, char *cmd)
{
	char **tab;
	int		i;
	int		y;

	y = 0;
	i = 0;
	tab = ft_calloc(sizeof(char *) * (nbr_args + is_flags(flags) + is_flags(cmd) + 1), &g_data);
	if (is_flags(cmd))
		tab[i++] = cmd;
	if (is_flags(flags))
		tab[i++] = flags;
	if (!args)
		return (tab);
	else
	{
		// printf("-%s-\n", args[0]);
		if (args[y])
		{
			while (args[y])
				tab[i++] = args[y++];
		}
	}
	// ft_print_args(tab);
	return (tab);
}