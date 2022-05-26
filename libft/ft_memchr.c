/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:22:15 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/10 15:48:14 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*dst;

	dst = (char *)s;
	i = 0;
	while (i < n)
	{
		if (dst[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
