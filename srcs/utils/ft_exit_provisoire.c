/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft _exit_provisoir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:25:47 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/08 12:25:57 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_exit_provisoire(char *str, int err)
{
	printf("%s", str);
	g_data.error = 1;
	g_data.status = err;
	// ft_garb_free_all(&g_data);
	// exit(err);
	return (err);
}