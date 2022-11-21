/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:11:05 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/21 18:01:09 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_env(void)
{
	int	i;

	i = 0;
	if (!g_data.env[i])
	{
		spe_env();
		return ;
	}
	while (g_data.env[i])
	{
		make_node(g_data.env[i]);
		i++;
	}
}

int	make_node(char *str)
{
	t_env	*new;
	int		size;

	size = ft_strlen(ft_strchr(str, '=') + 1);
	new = ft_malloc(sizeof(t_env), &g_data);
	if (!new)
		return (0);
	new->name = ft_malloc(find_signe(str) + 1, &g_data);
	new->str = ft_malloc(size + 1, &g_data);
	if (!new->name || ! new->str)
		return (0);
	ft_strlcpy(new->name, str, find_signe(str) + 1);
	ft_strlcpy(new->str, ft_strchr(str, '=') + 1, size + 1);
	new->next = NULL;
	new->prev = NULL;
	add_back_env(new);
	return (1);
}

int	add_back_env(t_env *new)
{
	t_env	*head;

	if (!g_data.env_head)
	{
		g_data.env_head = new;
		return (1);
	}
	head = g_data.env_head;
	while (head->next != NULL)
		head = head->next;
	head->next = new;
	new->prev = head;
	return (1);
}

int	find_signe(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (i);
}

int	env_size(void)
{
	t_env	*head;
	int		i;

	head = g_data.env_head;
	i = 0;
	while (head->next)
	{
		i++;
		head = head->next;
	}
	if (head)
		i++;
	return (i);
}
