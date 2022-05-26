/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:37:03 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/13 12:40:36 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!s)
		return (count);
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count ++;
		i++;
	}
	return (count);
}

static size_t	malloc_size(char const *s, size_t i, char c)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static size_t	mine_substr(char const *s, size_t i, char *strs, char c)
{
	size_t	j;

	if (!s)
		return (0);
	j = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		strs[j] = s[i];
		i++;
		j++;
	}
	strs[j] = '\0';
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char		**strs;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!strs)
		return (NULL);
	while (s[i] && j < count_word(s, c))
	{
		strs[j] = malloc(sizeof(char) * (malloc_size(s, i, c) + 1));
		if (!strs[j])
		{
			ft_free(strs);
			return (NULL);
		}
		i = mine_substr(s, i, strs[j], c);
		j++;
	}
	strs[j] = 0;
	return (strs);
}
