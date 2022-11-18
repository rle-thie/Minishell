/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:39:55 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/17 18:39:56 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_redir_error(t_redir *lst)
{
	while (lst && lst->next)
	{
		if (lst->type == FT_ERROR)
		{
			g_data.error = 1;
			g_data.status = 2;
			printf("Minishell: parse error'\n");
			return (1);
		}
		lst = lst->next;
	}
	if (lst)
	{
		if (lst->type == FT_ERROR)
		{
			g_data.error = 1;
			printf("Minishell: parse error\n");
			g_data.status = 2;
			return (1);
		}
	}
	return (0);
}

int	is_valid_redir_utils(char *str, int i)
{
	size_t count;

	count = 0;
	while (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == '<' || str[i] == '>' || str[i] == ' ' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\n')
		{
			count++;
		}
		i++;
	}
	if (count == ft_strlen(str))
		return (1);
	return (0);
}

int	is_valid_redir(t_redir *lst)
{
	int	i;

	i = 1;
	while (lst && lst->next)
	{
		i += is_valid_redir_utils(lst->file_name, 0);
		if (is_valid_redir_utils(lst->file_name, 0) == 1)
			lst->type = FT_ERROR;
		lst = lst->next;
	}
	if (lst)
	{
		i += is_valid_redir_utils(lst->file_name, 0);
		if (is_valid_redir_utils(lst->file_name, 0) == 1)
			lst->type = FT_ERROR;
	}
	return (i);
}
