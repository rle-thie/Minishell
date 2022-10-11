/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:07:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/05 18:23:07 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_unset(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		look_for_var(cmd[i]);
		i++;
	}
}

void	look_for_var(char *str)
{
	t_env	*head;

	head = g_data.env_head;
	while (head->next)
	{
		if (!ft_strncmp(str, head->name, ft_strlen(head->name)))
		{
			del_env_link(head);
			return ;
		}
		head = head->next;
	}
	return ;
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
	free(link);
	//attention peut-etre double free pour le garb
}

//doit essayer de suprimmer chaque arg donné
//faire attention que le prev ou next existe avant de switch des addr