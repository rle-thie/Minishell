/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:50:46 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/15 15:51:11 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd_error(char *str, int e)
{
	(void)str;
	if (e == 1)
		printf("bash: cd: too many arguments");
	else if (e == 2)
		printf("bash: cd: HOME not set");
	else
	{
		ft_putstr_fd("bash: cd: ", STDERR_FILENO);
		ft_putendl_fd(strerror(errno), STDERR_FILENO);
	}
	return (EXIT_FAILURE);
}
