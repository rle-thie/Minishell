/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:55:02 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/06 19:03:52 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lentt;
	char	*tab;
	size_t	i;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	y = 0;
	lentt = ft_strlen(s1) + ft_strlen(s2);
	tab = malloc(sizeof(char) * (lentt + 1));
	if (!tab)
		return (NULL);
	while (s1[y])
		tab[i++] = s1[y++];
	y = 0;
	while (s2[y])
		tab[i++] = s2[y++];
	tab[i] = '\0';
	return (tab);
}
