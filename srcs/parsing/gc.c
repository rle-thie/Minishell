/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:04:20 by rle-thie          #+#    #+#             */
/*   Updated: 2022/06/09 13:19:38 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_garb_add(t_data *data, t_garbage *new)
{
	while (data->garb->next)
		data->garb = data->garb->next;
	new->prev = data->garb;
	data->garb->next = new;
	while (data->garb->prev)
		data->garb = data->garb->prev;
}

t_garbage	*ft_garb_new(void *ptr_content, t_data *data)
{
	t_garbage *new;

	new = malloc(sizeof(*new));
	if(!new)
	{
		// proteger le malloc tout ca tu connais
		data = data;
		exit(1);
	}
	new->prev = NULL;
	new->next = NULL;
	new->ptr = ptr_content;
	return (new);
}

void	*ft_malloc(size_t size, t_data *data)
{
	void	*ptr;
	
	ptr = malloc(size);
	if (!ptr)
	{
		// securiser le malloc tout ca
		exit(1);
	}
	if (data->garb && data->garb->ptr)
	{
		ft_garb_add(data, ft_garb_new(ptr, data));
	}
	else if (data->garb)
	{
		data->garb->prev = NULL;
		data->garb->next = NULL;
		data->garb->ptr = ptr;
	}
	// parce que la fonction malloc return un ptr de base
	return (ptr);
}

void	*ft_calloc(size_t size, t_data *data)
{
	void	*ptr;
	
	ptr = malloc(size);
	ft_bzero(ptr, size);
	if (!ptr)
	{
		// securiser le malloc tout ca
		exit(1);
	}
	if (data->garb && data->garb->ptr)
	{
		ft_garb_add(data, ft_garb_new(ptr, data));
	}
	else if (data->garb)
	{
		data->garb->prev = NULL;
		data->garb->next = NULL;
		data->garb->ptr = ptr;
	}
	// parce que la fonction malloc return un ptr de base 
	return (ptr);
}