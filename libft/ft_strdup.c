/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:36:04 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/10 12:22:51 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cpy;
	int		j;

	j = 0;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	cpy = malloc(sizeof(char) * j + 1);
	if (cpy == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
