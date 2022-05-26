/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 18:15:12 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/13 15:55:36 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
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
	tab = malloc(sizeof(char) * (size_tab(n) + signe + 1));
	if (!tab)
		return (NULL);
	tab[size_tab(n) + signe] = '\0';
	fill_tab(i, signe, nbr, tab);
	return (tab);
}

// int	main(void)
// {
// 	printf("%s", ft_itoa(-1215));
// 	return (0);
// }
