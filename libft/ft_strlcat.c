/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:11:12 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/06 17:46:18 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	len_dst = 0;
	while (dst[len_dst])
		len_dst++;
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (len_dst >= size)
		return (size + len_src);
	i = -1;
	while (src[++i] && i < size - len_dst - 1)
		dst[len_dst + i] = src[i];
	dst[len_dst + i] = '\0';
	return (len_src + len_dst);
}
