/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:07:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/24 12:45:48 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_unset(char **cmd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (cmd[i])
	{
		if (look_for_var(cmd[i]))
			ret = 1;
		i++;
	}
	return (ret);
}

int	look_for_var(char *str)
{
	t_env	*head;

	head = g_data.env_head;
	while (head)
	{
		if (!ft_strncmp(str, head->name, ft_strlen(head->name)))
		{
			del_env_link(head);
			return (0);
		}
		head = head->next;
	}
	return (1);
}

void	del_env_link(t_env *link)
{
	if (link->prev == NULL)
	{
		g_data.env_head = link->next;
		g_data.env_head->prev = NULL;
	}
	else if (link->next == NULL)
		link->prev->next = NULL;
	else
	{
		link->prev->next = link->next;
		link->next->prev = link->prev;
	}
	ft_free(link, &g_data);
}
