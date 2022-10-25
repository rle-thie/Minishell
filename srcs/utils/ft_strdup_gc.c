/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_gc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 01:04:27 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/26 01:04:27 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strdup_gc(const char *s, t_data *data)
{
	int		i;
	char	*cpy;
	int		j;

	j = 0;
	while (s[j])
		j++;
	cpy = ft_malloc(sizeof(char) * j + 1, data);
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