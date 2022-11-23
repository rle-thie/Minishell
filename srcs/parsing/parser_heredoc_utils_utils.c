/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc_utils_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:39:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/23 15:39:25 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*del_last_n(char *str)
{
	char	*tab;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str) - 1;
	if (i < 0)
		return (NULL);
	tab = ft_calloc(sizeof(char) * 1, &g_data);
	while (i < len)
	{
		tab = ft_strjoinchar_gc(tab, str[i], &g_data);
		i++;
	}
	return (tab);
}

char	*put_heredoc(char *file)
{
	int		i;
	int		fd;
	char	*str;
	char	*tab;

	i = 0;
	tab = ft_calloc(sizeof(char) * 1, &g_data);
	fd = ft_open(file, O_RDONLY, 0, &g_data);
	while (i == 0)
	{
		str = get_next_line(fd);
		if (str && ft_strlen(str) >= 1)
		{
			str = del_last_n(str);
			str = expand_heredoc(str, 0);
			str = ft_strjoinchar_gc(str, '\n', &g_data);
			tab = ft_strjoin_gc(tab, str, &g_data);
		}
		else
			i = 1;
	}
	close_all(&g_data);
	return (tab);
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

int	check_eof(char *line, char *eof)
{
	char	*dst;

	dst = ft_strdup_gc(line, &g_data);
	if (!ft_strcmp(dst, eof))
	{
		ft_free(dst, &g_data);
		return (1);
	}
	ft_free(dst, &g_data);
	return (0);
}
