/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/05/25 17:47:03 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int ac, char const **av)
{
	t_data	data;
	char *str;

	ac=ac;
	av=av;
	// data = malloc(sizeof(t_data));
	data.garb = malloc(sizeof(t_garbage));
	// init_all(&data);
	data=data;
	

	str = ft_malloc(sizeof(char) * 3, &data);
	str=str;
	ft_garb_free_all(&data);
	// free(&data);
	return (0);
}
