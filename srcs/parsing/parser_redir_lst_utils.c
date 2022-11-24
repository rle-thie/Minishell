/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir_lst_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:19:52 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/23 15:19:53 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_one_redir(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == '<' || str[i] == '>'))
		{
			while (str[i] && (str[i] == '<' || str[i] == '>' || str[i] == ' '))
				i++;
			if (str[i] && ft_isprint(str[i]) == 1)
				c++;
		}
		i++;
	}
	return (c);
}

int	ft_strleni(char *str, int i)
{
	int	y;

	y = 0;
	while (str[i])
	{
		i++;
		y++;
	}
	return (y);
}
