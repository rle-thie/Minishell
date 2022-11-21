/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:03:11 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/18 16:25:53 by ldevy            ###   ########.fr       */
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
	if (!cmd[0])
		return (0);
	i = 0;
	if (cmd[index][i++] == '-')
	{
		while (cmd[index][i] == 'n')
			i++;
		if (cmd[index][i] && cmd[index][i] != 'n' && index == 1)
			return (0);
		return (1);
	}
	else
		return (0);
	return (0);
}

int	is_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'n')
			return (1);
		i++;
	}
	return (0);
}

int	is_flag_n(char **str)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (str[i])
	{
		if (str[i][0] == '-' && is_n(str[i]) == 1)
			y++;
		else if (str[i][0] != '-')
			return (y);
		i++;
	}
	return (y);
}

int	my_echo(char **cmd)
{
	int	new_line;
	int	index;

	index = 0;
	new_line = 0;
	if (is_flag_n(cmd) != 0)
	{
		index += is_flag_n(cmd);
		new_line = 1;
	}
	while (cmd && cmd[index])
	{
		ft_putstr_fd(cmd[index], STDOUT_FILENO);
		index++;
		if (cmd[index])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
	if (new_line == 0)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
