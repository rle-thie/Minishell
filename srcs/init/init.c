/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:13:45 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/11 23:53:13 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_garb(t_data *data)
{
	data->garb = malloc(sizeof(t_garbage));
	if (!data->garb)
		exit(1);
	data->garb->next = NULL;
	data->garb->prev = NULL;
	data->garb->ptr = NULL;
}

void	init_all(char **envp)
{
	t_data	data;

	data.token = NULL;
	data.formated_cmd = NULL;
	data.cmd = NULL;
	data.garb = NULL;
	data.env = envp;
	data.env_head = NULL;
	data.status = 0;
	data.error = 0;
	init_garb(&data);
	data.opened = NULL;
	g_data = data;
	init_env();
}