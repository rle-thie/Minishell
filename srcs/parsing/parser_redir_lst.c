/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:48:20 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/07 11:49:15 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_redir	*add_before_lst(t_redir *lst, char *str)
{
	t_redir	*new;

	new = ft_create_redir(str);
	if (!lst->prev)
	{
		lst->prev = new;
		new->next = lst;
		return (lst);
	}
	else if (lst->prev)
	{
		lst->prev->next = new;
		new->prev = lst->prev;
		lst->prev = new;
		new->next = lst;
		return (lst);
	}
	return (NULL);
}

char	*ft_strndup(char *str, int i)
{
	char	*tab;
	int		y;

	y = 0;
	tab = NULL;
	if (!str)
		return (NULL);
	tab = ft_calloc(sizeof(char) * i + 99, &g_data);
	while (str[i] && y <= i)
	{
		tab[y] = str[y];
		i++;
		y++;
	}
	return (tab);
}

char	*delete_first_redir(char *str, int i)
{
	int		len;
	char	*tab;
	int		y;

	y = 0;
	len = ft_strleni(str, i);
	tab = ft_calloc(sizeof(char) * len + 1, &g_data);
	while (str[i])
	{
		tab[y] = str[i];
		y++;
		i++;
	}
	return (tab);
}

t_redir	*divise_lst(char *str, t_redir *lst)
{
	char	*extract;
	int		i;

	extract = NULL;
	i = 0;
	while (str[i] && (str[i] == '<' || str[i] == '>' || str[i] == ' '))
		i++;
	while (str[i] && ft_isprint(str[i]) && str[i] != '<'
		&& str[i] != '>' && str[i] != ' ')
		i++;
	extract = ft_strndup(str, ft_strlen(str) - i);
	lst->file_name = &str[i];
	lst = add_before_lst(lst, extract);
	return (lst);
}

t_redir	*format_redir_lst(t_redir *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst->file_name = del_first_space(lst->file_name);
		if (check_one_redir(lst->file_name) >= 2)
		{
			while (check_one_redir(lst->file_name) >= 2)
				lst = divise_lst(lst->file_name, lst);
		}
		else
			lst = lst->next;
	}
	if (lst)
	{
		lst->file_name = del_first_space(lst->file_name);
		while (check_one_redir(lst->file_name) >= 2)
			lst = divise_lst(lst->file_name, lst);
	}
	while (lst->prev)
		lst = lst->prev;
	return (lst);
}
