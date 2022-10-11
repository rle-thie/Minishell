/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:12:13 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/10 17:37:13 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_pwd(char **cmd)
{
	char	*path;

	(void)cmd;
	path = getcwd((char *) NULL, 0);
	if (path == NULL)
	{
		return ; //erreur return value EXIT_FAILURE
	}
	else
	{
		ft_putstr_fd(path, STDOUT_FILENO);
		free(path);
		//return value EXIT_SUCCESS
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}
