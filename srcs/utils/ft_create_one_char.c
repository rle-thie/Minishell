/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_one_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 02:41:49 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/24 11:51:43 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*create_one_char(char c)
{
	char	*str;

	str = ft_calloc(sizeof(char) * 2, &g_data);
	str[0] = c;
	return (str);
}
