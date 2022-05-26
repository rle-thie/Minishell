/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:56:41 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/13 13:00:16 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest1;
	unsigned char	*src1;

	dest1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	i = -1;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (1 <= n)
		{
			dest1[n - 1] = src1[n -1];
			n--;
		}
	}
	else
	{
		while (++i < n)
			dest1[i] = src1[i];
	}
	dest = dest1;
	return (dest);
}
