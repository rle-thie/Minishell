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

void	format_redir_lst(t_redir *lst)
{
	if (!lst)
		return ;
	while (lst->next)
	{
		lst->file_name = del_first_space(lst->file_name);
		printf("'%s'\n", lst->file_name);
		lst = lst->next;
	}
	if (lst)
	{
		lst->file_name = del_first_space(lst->file_name);
		printf("'%s'\n", lst->file_name);
		lst = lst->next;
	}
}