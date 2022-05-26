/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 14:56:55 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/10 15:10:29 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	malloc_size(char const *s, unsigned int start, size_t len)
{
	size_t	size;

	size = 0;
	if (start > ft_strlen(s))
		return (size);
	while (s[start] && size < len)
	{
		size++;
		start++;
	}
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*dst;

	if (!s)
		return (NULL);
	i = 0;
	size = malloc_size(s, start, len);
	dst = malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	while (i < size && s[start])
		dst[i++] = s[start++];
	dst[i] = '\0';
	return (dst);
}
