/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_chevron.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:30:50 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 23:53:21 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_len(char *str)
{
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (str[i] && (str[i] == '<' || str[i] == '>'))
		i++;
	while (str[i])
	{
		i++;
		y++;
	}
	return (y);
}

char	*delete_pre(char *str)
{
	int		len;
	char	*tab;
	int		y;
	int		i;

	i = 0;
	y = 0;
	len = check_len(str);
	if (len <= 0)
		return (NULL);
	tab = ft_calloc(sizeof(char) * (len + 1), &g_data);
	while (str[i] && (str[i] == '<' || str[i] == '>'))
		i++;
	while (str[i])
	{
		tab[y] = str[i];
		i++;
		y++;
	}
	return (tab);
}

t_redir	*delete_chevron(t_redir *lst)
{
	while (lst && lst->next)
	{
		lst->file_name = delete_pre(lst->file_name);
		lst = lst->next;
	}
	if (lst)
		lst->file_name = delete_pre(lst->file_name);
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}
