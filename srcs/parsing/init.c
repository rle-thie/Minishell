/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 02:13:45 by rle-thie          #+#    #+#             */
/*   Updated: 2022/05/25 17:27:22 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	init_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->garb = malloc(sizeof(t_garbage));
	if (!data->garb)
	{
		free(data);
		exit(1);
	}
	
}

void	init_all(t_data *data)
{
	data=data;
	init_data(data);
}