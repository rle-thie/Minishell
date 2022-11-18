/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:54:34 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/16 19:02:58 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	err_msg(char *cmd)
{
	ft_putstr_fd("env : '", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
}

int	my_env(char **cmd)
{
	if (!cmd[0])
	{
		show_env();
		return (EXIT_SUCCESS);
	}
	else
	{
		err_msg(cmd[0]);
		return (127);
	}
}

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
}
