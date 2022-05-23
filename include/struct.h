/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:49:57 by rle-thie          #+#    #+#             */
/*   Updated: 2022/05/17 11:19:33 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCT_H
# define STRUCT_H

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;

struct	s_garbage
{
	struct s_garbage	*prev;
	void				*ptr;
	struct s_garbage	*next;
};

struct s_data
{
	struct s_garbage *garb;
};

#endif