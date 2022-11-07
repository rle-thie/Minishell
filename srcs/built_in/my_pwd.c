/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:12:13 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/31 19:59:10 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	my_pwd(char **cmd)
{
	char	*path;

	(void)cmd;
	path = getcwd((char *) NULL, 0);
	if (path == NULL)
		return (errno);
	else
	{
		ft_putstr_fd(path, STDOUT_FILENO);
		free(path);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
