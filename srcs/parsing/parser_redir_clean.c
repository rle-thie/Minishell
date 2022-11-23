/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir_clean.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:22:01 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/02 15:22:03 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*create_clean_redir(char *str, int len)
{
	char	*tab;
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (!len && !str)
		return (NULL);
	tab = ft_calloc(sizeof(char) * (len + 2), &g_data);
	while (str[i] && (str[i] == '>' || str[i] == '<'))
	{
		tab[y] = str[i];
		y++;
		i++;
	}
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		tab[y] = str[i];
		y++;
		i++;
	}
	return (tab);
}

char	*check_space(char *str, int i)
{
	char	*tab;
	int		y;

	y = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] && (str[i] == '>' || str[i] == '<'))
		{
			while (str[i] && (str[i] == '>' || str[i] == '<'))
				i++;
			while (str[i] && str[i] == ' ')
			{
				i++;
				y++;
			}
			while (str[i])
				i++;
		}
	}
	tab = create_clean_redir(str, i - y);
	return (tab);
}

t_token_type	check_type(char *str, int i)
{
	int	c;

	c = 0;
	while (str[++i] && (str[i] == '>' || str[i] == '<'))
		c++;
	if (c != 1 && c != 2)
		return (FT_ERROR);
	if (c == 1)
	{
		if (str[0] == '>')
			return (REDIR_OUT);
		else if (str[0] == '<')
			return (REDIR_IN);
	}
	else
	{
		if (str[0] == '>' && str[1] == '>')
			return (DOUBLE_REDIR_OUT);
		else if (str[0] == '<' && str[1] == '<')
			return (DOUBLE_REDIR_IN);
	}
	return (FT_ERROR);
}

void	init_redir_index(t_redir *lst)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		lst->index = i;
		lst = lst->next;
		i++;
	}
	if (lst)
		lst->index = i;
}

t_redir	*clean_all_redir(t_redir *lst)
{
	init_redir_index(lst);
	while (lst->next)
	{
		lst->file_name = check_space(lst->file_name, 0);
		lst->type = check_type(lst->file_name, -1);
		lst = lst->next;
	}
	if (lst)
	{
		lst->file_name = check_space(lst->file_name, 0);
		lst->type = check_type(lst->file_name, -1);
	}
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
