/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 01:13:48 by rle-thie          #+#    #+#             */
/*   Updated: 2022/05/23 02:28:53 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_free(void *ptr, t_data *data)
{
	while (data->garb != ptr && data->garb->next)
		data->garb = data->garb->next;
	if (data->garb == ptr)
	{
		// replace
		free(data->garb);
		return (1);
	}
	return (0);
}

void 	ft_garb_free_all(t_data *data)
{
	while (data->garb->next)
		data->garb = data->garb->next;
	while (data->garb->prev)
	{
		data->garb = data->garb->prev;
		free(data->garb->next->ptr);
		free(data->garb->next);
	}
	free(data->garb->ptr);
	free(data->garb);
}