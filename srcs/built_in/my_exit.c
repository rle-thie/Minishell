/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:49:00 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/13 20:18:05 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	nb_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	char_present(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_args(char **arg)
{
	int	i;

	i = 0;
	if (!arg)
		return (1);
	if (arg[i])
	{
		if (nb_args(arg) == 1 && !char_present(arg[i]))
			return (1);
		if ((char_present(arg[i])))
		{
			printf("bash: exit: %s: numeric argument required\n", arg[i]);
			return (1);
		}
		else if (nb_args(arg) > 1)
		{
			printf("bash: exit: too many arguments\n");
			return (0);
		}
	}
	return (1);
}

int	my_exit(char **arg)
{
	if (!check_args(arg))
		return (EXIT_FAILURE);
	rl_clear_history();
	ft_garb_free_all(&g_data);
	exit(EXIT_SUCCESS);
}
