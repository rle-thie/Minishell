/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/24 12:42:30 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data	g_data;

void	put_null_data(void)
{
	g_data.cmd = NULL;
	g_data.formated_cmd = NULL;
	g_data.token = NULL;
}

int	main(int ac, char **av, char **envp)
{
	char	*str;

	(void)ac;
	(void)av;
	init_all(envp);
	while (1)
	{
		g_data.error = 0;
		sig_init();
		str = readline(input_name());
		if (str && *str)
			add_history(str);
		if (!str)
			break ;
		lexer(str, &g_data);
		if (g_data.error == 0)
			parser();
		if (g_data.error == 0)
			parent_process();
		printf("\nEXIT STATUS : %d\n\n", g_data.status);
		put_null_data();
	}
	my_exit(NULL);
}
