/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/02 21:14:43 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	g_data;

int	main(int ac, char **av, char **envp)
{
	char	*str;

	(void)ac;
	(void)av;
	init_all(envp);

	while (1)
	{
		str = readline("Minishell : ");
		lexer(str, &g_data);
		parser();
		parent_process();
		printf("\nEXIT STATUS : %d\n\n", g_data.status);
		g_data.cmd = NULL;
		g_data.formated_cmd = NULL;
		g_data.token = NULL;
		// break ;
	}
	ft_garb_free_all(&g_data);
	return (0);
}
