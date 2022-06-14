/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:05:09 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/14 18:36:41 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

//echo
void	my_echo(char **cmd);
int		check_nl(char **cmd);
//pwd
void	my_pwd(char **cmd);

//env
void	my_env(char **cmd, t_data data);
void	err_msg(char *cmd);
void	print_env(t_data data);



#endif