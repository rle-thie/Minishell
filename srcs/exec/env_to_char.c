/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:36:58 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/20 16:38:46 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	reset_env_char(void)
{
	int	i;

	i = 0;
	while (g_data.env[i])
	{
		ft_free(g_data.env[i], &g_data);
		i++;
	}
	ft_free(g_data.env, &g_data);
}

void	struct_to_char(void)
{
	t_env	*head;
	int		size;
	int		i;

	i = 0;
	if (g_data.env)
		reset_env_char();
	g_data.env = ft_malloc(((env_size() + 1) * sizeof(*g_data.env)), &g_data);
	head = g_data.env_head;
	while (head->next)
	{
		size = ft_strlen(head->name) + ft_strlen(head->str) + 1;
		g_data.env[i] = ft_malloc(size, &g_data);
		g_data.env[i] = "";
		g_data.env[i] = ft_strjoin_gc(g_data.env[i], head->name, &g_data);
		g_data.env[i] = ft_strjoin_gc(g_data.env[i], "=", &g_data);
		g_data.env[i] = ft_strjoin_gc(g_data.env[i], head->str, &g_data);
		i++;
		head = head->next;
	}
	struct_to_char_p2();
}

void	struct_to_char_p2(void)
{
	t_env	*head;
	int		size;
	int		i;

	i = 0;
	head = g_data.env_head;
	while (head->next)
	{
		i++;
		head = head->next;
	}
	if (head)
	{
		size = ft_strlen(head->name) + ft_strlen(head->str) + 1;
		g_data.env[i] = ft_malloc(size, &g_data);
		g_data.env[i] = "";
		g_data.env[i] = ft_strjoin_gc(g_data.env[i], head->name, &g_data);
		g_data.env[i] = ft_strjoin_gc(g_data.env[i], "=", &g_data);
		g_data.env[i] = ft_strjoin_gc(g_data.env[i], head->str, &g_data);
	}
	g_data.env[i + 1] = NULL;
}
