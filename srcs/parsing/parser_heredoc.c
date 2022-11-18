/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:32:06 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/18 15:26:33 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_same(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (-2);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (-3);
		i++;
	}
	return (1);
}

// char	*put_null_char(char *str)
// {
// 	int len;
// 	int	i;
// 	char *tab;

// 	i = 0;
// 	if (!str)
// 		exit_eof();
// 	len = ft_strlen(str);
// 	tab = ft_calloc(sizeof(char) * (len + 1), &g_data);
// 	while (i < len)
// 	{
// 		tab[i] = str[i];
// 		i++;
// 	}
// 	// printf("-%s-\n", tab);
// 	return (tab);
// }

char	*create_heredoc(char *str, int i)
{
	char	*tab;
	char	*tab_join;

	tab_join = ft_calloc(sizeof(char) * 2, &g_data);
	tab_join[0] = ' ';
	while (1 && g_data.error == 0)
	{
		tab = readline("heredoc> ");
		// tab = put_null_char(tab);
		if (!tab || is_same(str, tab) == 1)
			break ;
		if (i != 0)
			tab_join = ft_strjoinchar_gc(tab_join, '\n', &g_data);
		tab_join = ft_strjoin_gc(tab_join, tab, &g_data);
		tab_join = expand_heredoc(tab_join, 0);
		i++;
	}
	if (!tab)
		printf("end of heredoc (%s)\n", str);
	if (ft_strlen(tab_join) <= 1)
		return ("\0");
	tab_join = del_first_space(tab_join);
	return (tab_join);
}

t_redir	*check_heredoc(t_redir *lst)
{
	if (g_data.error != 0)
		return (NULL);
	while (lst && lst->next)
	{
		if (lst->type == DOUBLE_REDIR_IN)
		{
			lst->file_name = create_heredoc(lst->file_name, 0);
			// if (lst->file_name)
			// 	lst->file_name = expand_var_herdoc(lst->file_name);
		}
		lst = lst->next;
	}
	if (lst && lst->type == DOUBLE_REDIR_IN)
	{
		lst->file_name = create_heredoc(lst->file_name, 0);
		// printf("'%s'\n",  lst->file_name);
		// if (lst->file_name)
		// 	lst->file_name = expand_var_herdoc(lst->file_name);
	}
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}
