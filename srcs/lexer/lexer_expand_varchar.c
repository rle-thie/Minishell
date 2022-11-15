/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand_varchar.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:41:43 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/14 13:41:44 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*find_env_var(char *str)
{
	t_env	*head;

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

// $PWD to rle-thie/sdljgdgjkgj/flsjfj
char	*expand_envvar(char *str, int i)
{
	char *tab;

	if (!str[i] && str[i + 1])
		return (NULL);
	// ft_printstr(str);
	tab = ft_calloc(sizeof(char) * 2, &g_data);
	tab[0] = ' ';
	i++;
	while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '\'')
	{
		printf("'%c'\n", str[i]);
		tab = ft_strjoinchar_gc(tab, str[i], &g_data);
		i++;
	}
	tab = del_first_space(tab);
	ft_printstr(tab);
	if (tab[0] && tab[0] == '?')
		tab = ft_itoa_gc(g_data.status);
	else if (find_env_var(tab))
		tab = find_env_var(tab);
	else
		tab = NULL;
	// printf("exp:-%s-\n", tab);
	return (tab);
}

char	*expand_varchar(char *str)
{
	char	*new;
	int		i;
	char	*tab;
	int		status;

	status = 0;
	i = 0;
	tab = ft_calloc(sizeof(char) * 2, &g_data);
	tab[0] = ' ';
	while (str[i])
	{
		// printf("'-%c'\n", str[i]);
		if (str[i] == '$' && str[i + 1] && str[i + 1] != '$' && str[i + 1] != ' ' && str[i + 1] != '\'')
		{
			new = expand_envvar(&str[i++], 0);
			if (new)
				tab = ft_strjoin_gc(tab, new, &g_data);
			// i++;
			if (str[i] && str[i++] == '?')
				status = 1;
			while (str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '\'' && status != 1)
			{
				// printf("'%c'\n", str[i]);
				i++;
			}
		}
		else
			tab = ft_strjoinchar_gc(tab, str[i++], &g_data);
	}
	tab = del_first_space(tab);
	// printf("final expand:-%s-\n", tab);
	return (tab);
}