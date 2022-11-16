/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_herdoc_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:49:03 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/15 16:49:04 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	isin_str(char str, char *search)
{
	int	i;

	i = 0;
	while (search[i])
	{
		if (str == search[i])
			return (0 - (1 + i));
		i++;
	}
	return (1);
}

char	*envvar(char *str)
{
	t_env	*head;

	if (!str)
		return (NULL);
	head = g_data.env_head;
	while (head->next)
	{
		if (!ft_strncmp(head->name, str, ft_strlen(str)))
			return (head->str);
		head = head->next;
	}
	if (head)
		if (!ft_strncmp(head->name, str, ft_strlen(str)))
			return (head->str);
	return (NULL);
}

char	*var_name(char *str)
{
	int		i;
	char	*tab;

	tab = ft_calloc(sizeof(char) * 2, &g_data);
	tab[0] = ' ';
	i = 0;
	while (str[i] && isin_str(str[i], "$\'\" ") == 1)
	{
		tab = ft_strjoinchar_gc(tab, str[i], &g_data);
		i++;
	}
	// if (isin_str(str[i], "$\'\" ") != 1)
	// 	printf("%d\n", isin_str(str[i], "$\'\" "));
	tab = del_first_space(tab);
	return (tab);
}

// toute la ligne
char	*expand_heredoc(char *str, int i)
{
	char	*tab;
	char	*new;

	tab = ft_calloc(sizeof(char) * 2, &g_data);
	tab[0] = ' ';
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] == '?')
		{
			tab = ft_strjoin_gc(tab, ft_itoa_gc(g_data.status), &g_data);
			i = i + 2;
		}
		else if (str[i] == '$' && str[i + 1] && isin_str(str[i + 1], "$\'\" ") == 1)
		{
			new = var_name(&str[i + 1]);
			if (envvar(var_name(&str[i + 1])))
				tab = ft_strjoin_gc(tab, envvar(new), &g_data);
			i++;
			while (str[i] && isin_str(str[i], "$\'\" ") == 1)
				i++;
		}
		else
			tab = ft_strjoinchar_gc(tab, str[i++], &g_data);
	}
	return (del_first_space(tab));
}