/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:09 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/15 15:24:50 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

//echo
int		my_echo(char **cmd);
int		check_nl(char **cmd);

//pwd
int		my_pwd(char **cmd);

//env
int		my_env(char **cmd);
void	err_msg(char *cmd);
void	print_env(t_data data);
void	show_env(void);

//unset
int		my_unset(char **cmd);
int		look_for_var(char *str);
void	del_env_link(t_env *link);

//my_export
int		my_export(char **cmd);
void	env_order(void);
int		check_env_index(char *str);
int		void_arg_export_checker(char *str);

//my_cd
int		my_cd(char **cmd);
int		ft_cd_error(char *str, int e);
char	*get_home(void);
void	change_pwds(void);
t_env	*find_cd_link(char *str);

//my_exit
int		nb_args(char **args);
int		char_present(char *str);
int		check_args(char **arg);
int		my_exit(char **cmd);

#endif