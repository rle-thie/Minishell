/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/05/23 02:31:26 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int ac, char const **av)
{
	t_data	*data;

	ac=ac;
	av=av;
	// ft_malloc(5, &data);
	data = malloc(sizeof(t_data));
	data->garb = malloc(sizeof(t_garbage));
	ft_garb_free_all(data);
	free(data);
	return (0);
}
