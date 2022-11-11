/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_gc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 01:18:32 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 01:24:05 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	size_tab(int nbr)
{
	unsigned int	i;
	long			n;

	n = (long)nbr;
	i = 1;
	if (n < 0)
		n = n * -1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*fill_tab(int i, int signe, long nbr, char *tab)
{
	if (signe == 1)
		tab[0] = '-';
	while (nbr > 9)
	{
		tab[i--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	tab[i] = (nbr % 10) + 48;
	return (tab);
}

char	*ft_itoa_gc(int n)
{
	long	nbr;
	int		signe;
	char	*tab;
	int		i;

	nbr = (long)n;
	signe = 0;
	if (nbr < 0)
	{
		signe = 1;
		nbr *= -1;
	}
	i = size_tab(n) + signe - 1;
	tab = ft_malloc(sizeof(char) * (size_tab(n) + signe + 1), &g_data);
	if (!tab)
		return (NULL);
	tab[size_tab(n) + signe] = '\0';
	fill_tab(i, signe, nbr, tab);
	return (tab);
}