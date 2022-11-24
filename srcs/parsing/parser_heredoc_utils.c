/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:39:26 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/23 15:39:27 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	sig_reset(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	free_all(t_data *data)
{
	data = data;
	ft_garb_free_all(&g_data);
	rl_clear_history();
}

int	exit_heredoc_fork(t_data *data, int dup_stdin)
{
	dup_stdin = dup_stdin;
	data = data;
	close (0);
	close(dup_stdin);
	close_all(data);
	free_all(data);
	exit (g_data.status);
}

void	exec_error(t_data *data)
{
	free_all(data);
	data->status = 255;
	exit(data->status);
}

int	no_line_return(int i, char *eof)
{
	char	p1;
	char	p2;

	p1 = '(';
	p2 = ')';
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("warning: here-document at line ", 2);
	ft_putstr_fd(ft_itoa_gc(i), 2);
	ft_putstr_fd(" delimited by end-of-file ", 2);
	write(2, &p1, 1);
	ft_putstr_fd("wanted `", 2);
	ft_putstr_fd(eof, 2);
	ft_putstr_fd("'", 2);
	write(2, &p2, 1);
	ft_putstr_fd("\n", 2);
	return (0);
}
