/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:23:58 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/07 12:33:37 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INIT_ENV_H
# define INIT_ENV_H



void	init_env(void);
int		make_node(char *str);
int		add_back_env(t_env *new);
int		find_signe(char *str);
int		env_size(void);

#endif