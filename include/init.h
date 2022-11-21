/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:16:50 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/21 18:10:20 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

// prompt
char	*input_name(void);

// garbage collector init/create
void	ft_garb_add(t_data *data, t_garbage *new);
t_garbage	*ft_garb_new(void *ptr_content, t_data *data);

// ft_Malloc
void	*ft_malloc(size_t size, t_data *data);
void	*ft_calloc(size_t size, t_data *data);

// free all & free addr
void 	ft_garb_free_all(t_data *data);
void	ft_free(void *ptr, t_data *data);

// init all
void	init_all(char **envp);
void		init_garb(t_data *data);

// init_env
void	init_env(void);
int		make_node(char *str);
int		add_back_env(t_env *new);
int		find_signe(char *str);
int		env_size(void);
void	spe_env(void);

// fd_opened;
t_opened	*ft_opened_new(int fd, t_data *data);
void	opened_addback(t_opened *new, t_data *data);
void	close_all(t_data *data);
int	ft_open(char *filename, int flags, int mod, t_data *data);

#endif