/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:32:06 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/21 12:45:51 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_same(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (-1);
	if (ft_strlen(str1) != ft_strlen(str2))
		return (-2);
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (-3);
		i++;
	}
	return (1);
}

// char	*put_null_char(char *str)
// {
// 	int len;
// 	int	i;
// 	char *tab;

// 	i = 0;
// 	if (!str)
// 		exit_eof();
// 	len = ft_strlen(str);
// 	tab = ft_calloc(sizeof(char) * (len + 1), &g_data);
// 	while (i < len)
// 	{
// 		tab[i] = str[i];
// 		i++;
// 	}
// 	// printf("-%s-\n", tab);
// 	return (tab);
// }

// char	*create_heredoc(char *str, int i)
// {
// 	char	*tab;
// 	char	*tab_join;

// 	tab_join = ft_calloc(sizeof(char) * 2, &g_data);
// 	tab_join[0] = ' ';
// 	while (1 && g_data.error == 0)
// 	{
// 		tab = readline("heredoc> ");
// 		// tab = put_null_char(tab);
// 		if (!tab || is_same(str, tab) == 1)
// 			break ;
// 		if (i != 0)
// 			tab_join = ft_strjoinchar_gc(tab_join, '\n', &g_data);
// 		tab_join = ft_strjoin_gc(tab_join, tab, &g_data);
// 		tab_join = expand_heredoc(tab_join, 0);
// 		i++;
// 	}
// 	if (!tab)
// 		printf("end of heredoc (%s)\n", str);
// 	if (ft_strlen(tab_join) <= 1)
// 		return ("\0");
// 	tab_join = del_first_space(tab_join);
// 	return (tab_join);
// }

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	sig_reset(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	free_all(t_data *data)
{
	data=data;
	ft_garb_free_all(&g_data);
	// free(data);
	rl_clear_history();
}

int	exit_heredoc_fork(t_data *data, int dup_stdin)
{

	dup_stdin=dup_stdin;
	data=data;
	close (0);
	close(dup_stdin);
	close_all(data);
	free_all(data);
	exit (g_data.status);
}

void	exec_error(t_data *data)
{
	// error(NULL, NULL, msg);
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

void	copy_in_heredoc(int fd, char *s)
{
	char	*dst;

	if (!s)
		return ;
	else
	{
		dst = ft_strdup_gc(s, &g_data);
		ft_free(s, &g_data);
	}
	write(fd, dst, ft_strlen(dst));
	ft_free(dst, &g_data);
}

void	error_ctrld(char *eof)
{
	ft_putstr_fd("minishell: end of heredoc (wanted `", 2);
	ft_putstr_fd(eof, 2);
	ft_putstr_fd("')\n", 2);
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
		if (!line && !heredoc_loop_return(*content, line, eof))
		{
			// error_ctrld(eof);
			break;
		}
		if (!ft_strcmp(line, eof))
			break;
		if (!*content)
			*content = ft_strdup_gc(line, &g_data);
		else
			*content = ft_strjoin_gc(*content, line, &g_data);
		*content = ft_strjoinchar_gc(*content, '\n', &g_data);
		free(line);
	}
	return (heredoc_loop_return(*content, line, eof));
}

int create_heredoc(char *str, char *content)
{
	int		fd;
	pid_t	pid;
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
		fd = ft_open("/tmp/.heredocss", O_CREAT | O_WRONLY | O_TRUNC, 0644, &g_data);
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
	// printf("status:%d\n", g_data.status);
	return (g_data.status);
}

char	*put_heredoc(char *file)
{
	int		i;
	int		fd;
	char	*str;
	char	*tab;

	tab = ft_calloc(sizeof(char) * 2, &g_data);
	tab[0] = '\0';
	i = 0;
	str = NULL;
	fd = ft_open(file, O_RDONLY, 0, &g_data);
	while (i == 0)
	{
		str = get_next_line(fd);
		if (str && ft_strlen(str) >= 1)
		{
			tab = ft_strjoin_gc(tab, str, &g_data);
		}
		else
			i = 1;
	}
	close_all(&g_data);
	// printf("%s\n", tab);
	return (tab);
}

t_redir	*check_heredoc(t_redir *lst)
{
	char	*content;

	content = NULL;
	if (g_data.error != 0)
		return (NULL);
	while (lst && lst->next)
	{
		if (lst->type == DOUBLE_REDIR_IN)
		{
			g_data.status = create_heredoc(lst->file_name, content);
			if (g_data.status != 130)
				lst->file_name = put_heredoc("/tmp/.heredocss");
			else
				g_data.error = 1;
			// g_data.str_tmp = NULL;
			// if (lst->file_name)
			// 	lst->file_name = expand_var_herdoc(lst->file_name);
		}
		lst = lst->next;
	}
	if (lst && lst->type == DOUBLE_REDIR_IN)
	{
		g_data.status = create_heredoc(lst->file_name, content);
		if (g_data.status != 130)
			lst->file_name = put_heredoc("/tmp/.heredocss");
		else
			g_data.error = 1;
		// printf("'%s'\n", lst->file_name);
		// printf("'%s'\n",  lst->file_name);
		// g_data.str_tmp = NULL;
		// lst->file_name = ft_strdup_gc(lst->file_name, &g_data);
		// if (content)
		// 	free(content);
		// if (lst->file_name)
		// 	lst->file_name = expand_var_herdoc(lst->file_name);
	}
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}
