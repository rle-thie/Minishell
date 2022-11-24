/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_provisoire.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:25:47 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/24 12:08:49 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_exit_provisoire(char *str, int err)
{
	ft_putstr_fd(str, 2);
	g_data.error = 1;
	g_data.status = err;
	return (err);
}
