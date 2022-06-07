/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/06/07 04:04:14 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int main(int ac, char const **av, char **envp)
{
	t_data *data;
	char *str;
	
	(void)ac;
	(void)av;
	data = init_all(envp);

	envp = envp;
	while (1)
	{
		str = readline("Minishell : ");
		lexer(str, data);
		break;
	}
	ft_garb_free_all(data);
	return (0);
}
