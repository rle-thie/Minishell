/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 01:13:48 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/13 01:30:13 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void 	ft_garb_free_all(t_data *data)
{
	while (!data->garb || data->garb->next != NULL)
		data->garb = data->garb->next;
	while (data->garb->prev)
	{
		data->garb = data->garb->prev;
		free(data->garb->next->ptr);
		free(data->garb->next);
	}
	if (data->garb)
	{
		free(data->garb->ptr);
		free(data->garb);
	}
	// free(data);
}