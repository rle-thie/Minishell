/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:32:06 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/22 12:52:24 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	heredoc_loop_return(char *content, char *line, char *eof)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (content && content[i])
	{
		if (content[i] == '\n')
			j++;
		i++;
	}
	if (!line)
		return (no_line_return(j, eof));
	free(line);
	return (0);
}

int	heredoc_loop(char **content, char *eof)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("heredoc> ");
		if (g_data.status == 130)
			return (1);
		if (!line || !ft_strcmp(line, eof) || check_eof(line, eof))
			break ;
		if (!ft_strcmp(line, eof))
			break ;
		if (!*content)
			*content = ft_strdup_gc(line, &g_data);
		else
			*content = ft_strjoin_gc(*content, line, &g_data);
		*content = ft_strjoinchar_gc(*content, '\n', &g_data);
		free(line);
	}
	return (heredoc_loop_return(*content, line, eof));
}

int	create_heredoc(char *str, char *content)
{
	pid_t	pid;
	int		fd;
	int		dup_stdin;

	sig_reset();
	dup_stdin = dup(0);
	pid = fork();
	if (pid < 0)
		exec_error(&g_data);
	if (pid == 0)
	{
		sig_handler_heredoc();
		dup2(dup_stdin, 0);
		fd = ft_open("/tmp/.hdss", O_CREAT | O_WRONLY | O_TRUNC, 0644, &g_data);
		if (fd < 0)
			exec_error(&g_data);
		if (heredoc_loop(&content, str))
			exit_heredoc_fork(&g_data, dup_stdin);
		copy_in_heredoc(fd, content);
		exit_heredoc_fork(&g_data, dup_stdin);
	}
	waitpid(pid, &g_data.status, 0);
	g_data.status = g_data.status % 255;
	close(dup_stdin);
	return (g_data.status);
}

t_redir	*check_heredoc(t_redir *lst, char *content)
{
	content = NULL;
	if (g_data.error != 0)
		return (NULL);
	while (lst && lst->next)
	{
		if (lst->type == DOUBLE_REDIR_IN)
		{
			g_data.status = create_heredoc(lst->file_name, content);
			if (g_data.status != 130)
				lst->file_name = put_heredoc("/tmp/.hdss");
			else
				g_data.error = 1;
		}
		lst = lst->next;
	}
	if (lst && lst->type == DOUBLE_REDIR_IN)
	{
		g_data.status = create_heredoc(lst->file_name, content);
		if (g_data.status != 130)
			lst->file_name = put_heredoc("/tmp/.hdss");
		else
			g_data.error = 1;
	}
	return (lst_put_start(lst));
}
