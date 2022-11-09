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

typedef struct s_sigs
{
	struct sigaction	sint;
	struct sigaction	sexit;
}	t_sigs;

void	handle_sigctlc(int sig)
{
	printf("\nMinishell : ");
	(void)sig;
}

void	sig_init(void)
{
	t_sigs	sig;

	ft_memset(&(sig.sexit), 0, sizeof(sig.sexit));
	ft_memset(&(sig.sint), 0, sizeof(sig.sint));
	sig.sint.sa_handler = &handle_sigctlc;
	sig.sint.sa_flags = SA_RESTART;
	sig.sexit.sa_handler = SIG_IGN;
	sig.sexit.sa_flags = SA_RESTART;
	sigaction(SIGINT, &(sig.sint), NULL);
	sigaction(SIGQUIT, &(sig.sexit), NULL);
}

int	main(int ac, char **av, char **envp)
{
	char	*str;

	(void)ac;
	(void)av;
	init_all(envp);
	sig_init();
	while (1)
	{
		str = readline("Minishell : ");
		if (!str)
		{
			printf("exit\n");
			break ;
		}
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
