/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:21:49 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/18 15:24:54 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_sigctlc(int sig)
{
	// printf("\n%s", input_name());
	g_data.status = 130;
	ft_putstr_fd("\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	(void)sig;
	// g_data.error = 1;
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
	g_data.sig = sig;
}

void	sig_heredoc(int sig)
{
	if (sig == SIGINT)
	{
		close(0);
		g_data.status = 130;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

void	sig_handler_heredoc(void)
{
	signal(SIGINT, sig_heredoc);
	signal(SIGQUIT, SIG_IGN);
}