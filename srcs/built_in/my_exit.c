/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:49:00 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/23 14:53:23 by ldevy            ###   ########.fr       */
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
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (1);
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
		return (4);
	if (arg[i])
	{
		if (nb_args(arg) == 1 && !char_present(arg[i]))
			return (1);
		if ((char_present(arg[i])))
		{
			printf("bash: exit: %s: numeric argument required\n", arg[i]);
			return (2);
		}
		else if (nb_args(arg) > 1)
		{
			printf("bash: exit: too many arguments\n");
			return (0);
		}
	}
	return (4);
}

int	my_exit(char **arg)
{
	int	ret;
	int	state;

	state = check_args(arg);
	if (state == 0)
		return (EXIT_FAILURE);
	else if (state == 4)
		ret = g_data.status;
	else if (state == 2)
		ret = 2;
	else if (state == 1)
		ret = ft_atoi(arg[0]);
	printf("exit\n");
	rl_clear_history();
	ft_garb_free_all(&g_data);
	exit(ret % 256);
}
