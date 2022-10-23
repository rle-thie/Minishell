/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 03:29:06 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/19 19:02:47 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UTILS_H
# define UTILS_H

char	*ft_strjoin_gc(char *s1, char *s2, t_data *data);

void	ft_print_token(t_token *token);
void	ft_print_formated(t_cmd *token);
void	ft_print_args(char **str);
void	print_bool(t_cmd *cmd);

#endif