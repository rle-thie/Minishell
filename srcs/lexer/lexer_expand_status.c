/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand_status.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:54:44 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 01:24:46 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*expand_status(char *str)
{
	char	*tab;
	char	*str_status;
	int 	len_status;
	int 	len_str;

	str_status = ft_itoa_gc(g_data.status);
	if(ft_strlen(str) == 1)
		return (str_status);
	len_status = ft_strlen(str_status);
	len_str = ft_strlen(str) - 1;
	tab = ft_calloc(sizeof(char) * len_status + len_str + 1, &g_data);
	tab = ft_strjoin_gc(str_status, &str[1], &g_data);
	// printf("-%s-\n", tab);
	return (tab);
}