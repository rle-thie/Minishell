/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:16:50 by rle-thie          #+#    #+#             */
/*   Updated: 2022/05/26 15:33:32 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	INIT_H
# define INIT_H


// garbage collector
void	ft_garb_add(t_data *data, t_garbage *new);
t_garbage	*ft_garb_new(void *ptr_content, t_data *data);
void		*ft_malloc(size_t size, t_data *data);
void 	ft_garb_free_all(t_data *data);

t_data	*init_all(char **envp);
void	init_garb(t_data *data);

#endif