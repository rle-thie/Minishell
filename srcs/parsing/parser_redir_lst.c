/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:48:20 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/27 15:48:20 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*del_first_space(char *str)
{
	char	*str2;
	int		i;

	i = 1;
	str2 = NULL;
	if (ft_strlen(str) <= 1)
		return (NULL);
	if (str[0] != ' ')
		return (str);
	str2 = ft_calloc(sizeof(char) * (ft_strlen(str) - 1 + 1), &g_data);
	while (str[i])
	{
		str2[i - 1] = str[i];
		i++;
	}
	ft_free(str, &g_data);
	return (str2);
}

int	check_one_redir(char *str)
{
	int	i;
	int	c;
	int	t;

	t = 0;
	c = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>')
		{
			i++;
			if (str[i] && (str[i] == '<' || str[i] == '>'))
				i++;
			while (str[i] && str[i] == ' ')
			{
				i++;
			}
			if (str[i] && isalnum(str[i]))
			{
				c++;
				t++;
			}
		}
		i++;
	}
	printf("%d\n", c);
	return (c);
}

// void	divise_lst(char *str)
// {
// 	while ()
// }

// fonction pour ajouter juste apres la liste X add_after(lst)
void	add_after_lst(t_redir *lst, char *str)
{
	t_redir	*new;

	new = ft_create_redir(str);
	if (!lst->next)
	{
		lst->next = new;
		new->prev = lst;
	}
	else if (lst->next)
	{
		lst->next->prev = new;
		new->next = lst->next;
		lst->next = new;
		new->prev = lst;
	}
}

void	format_redir_lst(t_redir *lst)
{
	if (!lst)
		return ;
	while (lst->next)
	{
		lst->file_name = del_first_space(lst->file_name);
		check_one_redir(lst->file_name);
		printf("'%s'\n", lst->file_name);
		lst = lst->next;
	}
	if (lst)
	{
		lst->file_name = del_first_space(lst->file_name);
		if (check_one_redir(lst->file_name) >= 2)
			divise_lst(lst->file_name);
		printf("'%s'\n", lst->file_name);
		lst = lst->next;
	}
}