/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:54:34 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/05 17:37:53 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	err_msg(char *cmd)
{
	ft_putstr_fd("env : '", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	//return status EXIT_FAILURE
}

void	my_env(char **cmd)
{
	if (!cmd[1])
		show_env();
	else
		err_msg(cmd[1]);
	(void)cmd;
}

//je pense qu'il faut mettre les variables d'env dans une 
//liste chainée pour eviter les pbs de var vide et 
//pour pouvoir supprimer une var sans que ça pose plus de pbs
//dans le reste du code  FAIT

void	show_env(void)
{
	t_env	*head;
	int		i;

	i = 0;
	head = g_data.env_head;
	while (head->next)
	{
		printf("%s=%s\n", head->name, head->str);
		head = head->next;
		i++;
	}
	printf("%s=%s\n", head->name, head->str);
	//return status EXIT_SUCCESS
	//printf("Number of env var shown : %d\n", i);
}
