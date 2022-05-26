/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:46:57 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/13 12:47:02 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		nbr1;
	int		nb;

	nb = n;
	if (nb == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			nbr1 = nb * -1;
			ft_putnbr_fd(nbr1, fd);
		}
		else
		{
			nbr1 = nb;
			while (nbr1 > 9)
			{
				ft_putnbr_fd(nbr1 / 10, fd);
				nbr1 = nbr1 % 10;
			}
			ft_putchar_fd(nbr1 + 48, fd);
		}
	}
}
