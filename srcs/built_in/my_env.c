/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:54:34 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/14 18:36:35 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	err_msg(char *cmd)
{
	ft_putstr_fd("env : '", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("’: No such file or directory\n", STDERR_FILENO);
	//return status EXIT_FAILURE
}

void	print_env(t_data data)
{
	int	i;

	i = 0;
	while (data.env[i])
	{
		ft_putstr_fd(data.env[i], STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		i++;
	}
	//retunr status EXIT_SUCCESS
}

void	my_env(char **cmd, t_data data)
{
	if (!cmd[1])
		print_env(data);
	else
		err_msg(cmd[1]);
	(void)cmd;
}

//je pense qu'il faut mettre les variables d'env dans une 
//liste chainée pour eviter les pbs de var vide et 
//pour pouvoir supprimer une var sans que ça pose plus de pbs
//dans le reste du code 