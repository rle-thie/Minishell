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

int	check_one_redir(char *str)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	// printf("'%s'\n", str);
	while (str[i])
	{
		if (str[i] && (str[i] == '<' || str[i] == '>'))
		{
			while (str[i] && (str[i] == '<' || str[i] == '>' || str[i] == ' '))
			{
				// printf("'%c'\n", str[i]);
				i++;
			}
			if (str[i] && ft_isprint(str[i]) == 1)
			{
				// printf("'caca:%c'\n", str[i]);
				c++;
			}
		}
		i++;
	}
	// printf("%d\n", c);
	return (c);
}

t_redir	*add_before_lst(t_redir *lst, char *str)
{
	t_redir	*new;

	new = ft_create_redir(str);
	if (!lst->prev)
	{
		lst->prev = new;
		new->next = lst;
		// lst = lst->prev;
		return (lst);
	}
	else if (lst->prev)
	{
		lst->prev->next = new;
		new->prev = lst->prev;
		lst->prev = new;
		new->next = lst;
		// lst = lst->prev;
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
	// char *str2;
	char *extract;
	extract = NULL;
	int	i;

	i = 0;
	
	// str2 = ft_calloc(sizeof(char) * 2, &g_data);
	// str2[0] = ' ';
	while (str[i] && (str[i] == '<' || str[i] == '>' || str[i] == ' '))
		i++;
	while (str[i] && ft_isprint(str[i]) && str[i] != '<' && str[i] != '>' && str[i] != ' ')
		i++;
	// printf("ptr:'%s'\n", &str[i]);
	extract = ft_strndup(str, ft_strlen(str) - i);
	// printf("extract:'%s'\n", extract);
	// str2 = ft_strjoin_gc(str2, extract, &g_data);
	// printf("nouv:'%s'\n", str2);
	// printf("tmp:'%s'\n", extract);
	// lst->file_name = delete_first_redir(str, i);
	lst->file_name = &str[i];
	lst = add_before_lst(lst, extract);
	// ft_printstr(str);
	
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