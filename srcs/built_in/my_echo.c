/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:03:11 by ldevy             #+#    #+#             */
/*   Updated: 2022/06/09 18:45:42 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// je vais avoir besoin de "echo", "-nnnnnnnnn", "nique ta memer=ed", NULL
//on considere l'option valide que si "-n" ou "-nnnnnnnn" mais pas "-n- dsfsdef"

int	check_nl(char **cmd)
{
	int	index;
	int	i;

	index = 0;
	while (cmd[++index])
	{
		i = 0;
		if (cmd[index][i++] == '-')
		{
			while (cmd[index][i] == 'n')
				i++;
			if (cmd[index][i] && cmd[index][i] != 'n')
				return (index);
		}
		else
			return (index);
	}
	return (index);
}

void	my_echo(char **cmd)
{
	int	new_line;
	int	index;

	index = 1;
	new_line = check_nl(cmd);
	if (!new_line)
		index++;
	while (cmd[index])
	{
		ft_putstr_fd(cmd[index], STDOUT_FILENO);
		index++;
		if (cmd[index])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (!new_line)
		ft_putstr_fd("\n", STDOUT_FILENO);
	//$? = EXIT_SUCCESS no idea comment on gere ça
}