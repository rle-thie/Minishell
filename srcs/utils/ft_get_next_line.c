/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:24:54 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/21 11:29:06 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*free_ptr(char *tab)
{
	ft_free(tab, &g_data);
	return (NULL);
}

char	*ft_strtrim_front(char *str)
{
	char		*stat;
	size_t		i;
	size_t		y;

	i = 0;
	y = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (free_ptr(str));
	stat = ft_malloc(sizeof(char) * (ft_strlen(str) - i + 1), &g_data);
	if (!stat)
		return (NULL);
	stat[(ft_strlen(str) - i) - 1] = '\0';
	if (str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		stat[y] = str[i];
		i++;
		y++;
	}
	ft_free(str, &g_data);
	return (stat);
}

char	*read_buff(int fd, char *stat, int buffer_size)
{
	int		count;
	char	*buf;

	count = 1;
	buf = ft_malloc(sizeof(char) * buffer_size + 1, &g_data);
	if (!buf)
		return (NULL);
	buf[0] = '\0';
	while (ft_strchr(buf, '\n') == 0 && count > 0)
	{
		count = read(fd, buf, buffer_size);
		if (count < 0)
			break ;
		buf[count] = '\0';
		stat = ft_strjoin_gc(stat, buf, &g_data);
	}
	ft_free(buf, &g_data);
	return (stat);
}

char	*read_line(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
		line = ft_malloc(sizeof(char) * i + 1, &g_data);
	else
		line = ft_malloc(sizeof(char) * i + 2, &g_data);
	if (!line)
		return (free_ptr(line));
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;
	int			buffer_size;

	buffer_size = 1;
	if (fd < 0 || buffer_size < 1)
		return (NULL);
	if (!buf)
	{
		buf = ft_malloc(sizeof(char) * 1, &g_data);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	buf = read_buff(fd, buf, buffer_size);
	if (!buf)
		return (NULL);
	line = read_line(buf);
	buf = ft_strtrim_front(buf);
	return (line);
}