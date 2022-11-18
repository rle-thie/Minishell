/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/07 16:52:21by ldevy            ###   ########.fr       */
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
	sig_init();
	while (1)
	{
		g_data.error = 0;
		sigaction(SIGINT, &(g_data.sig.sint), NULL);
		// str = readline(input_name());
		str = readline("mini:");
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
		g_data.cmd = NULL;
		g_data.formated_cmd = NULL;
		g_data.token = NULL;
	}
	printf("exit\n");
	my_exit(NULL);
}
