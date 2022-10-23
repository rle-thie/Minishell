/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_flags_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:22:21 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/23 17:22:33 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*put_tiret(char *str)
{
	char	*flags;

	if (!str)
		return (NULL);
	flags = ft_calloc(sizeof(char) * (ft_strlen(str) + 2), &g_data);
	flags[0] = '-';
	flags = ft_strjoin_gc(flags, str, &g_data);
	ft_free(str, &g_data);
	return (flags);
}