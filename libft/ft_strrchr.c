/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:25:20 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/10 17:00:29 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	while (s[i] && s[len] != (char)c)
	{
		i++;
		len--;
	}
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	else
		return (NULL);
}
