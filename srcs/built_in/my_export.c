/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:11:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/06 20:36:31 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_export(char **cmd)
{
	int	i;

	i = 1;
	while (cmd[i])
	{
		env_order();
		i++;
		//exit status success
	}
}

void	env_order(void)
{
	int		size;
	t_env	*head;

	size = env_size() - 1;
	while (size > 1)
	{
		head = g_data.env_head;
		while (head->next)
		{
			if (check_env_index(head->name) == size)
			{
				printf("declare -x %s=\"%s\"\n", head->name, head->str);
				size--;
			}
			head = head->next;
		}
		if (head)
		{
			if (check_env_index(head->name) == size && size > 2)
			{
				printf("declare -x %s=\"%s\"\n", head->name, head->str);
				size--;
			}
		}
	}
}

// static void	print_error(char *str)
// {
// 	ft_putstr_fd("bash: export: `", STDERR_FILENO);
// 	ft_putstr_fd(str, STDERR_FILENO);
// 	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
// 	//exit status failure
// }

int	check_env_index(char *str)
{
	t_env	*head;
	int		i;
	int		buff;

	i = 0;
	head = g_data.env_head;
	while (head->next)
	{
		buff = ft_strlen(str) + ft_strlen(head->name);
		if (ft_strncmp(str, head->name, buff) < 0)
			i++;
		head = head->next;
	}
	if (head)
	{
		buff = ft_strlen(str) + ft_strlen(head->name);
		if (ft_strncmp(str, head->name, buff) < 0)
			i++;
	}
	return (i);
}

int	env_size(void)
{
	t_env	*head;
	int		i;

	head = g_data.env_head;
	i = 0;
	while (head->next)
	{
		i++;
		head = head->next;
	}
	if (head)
		i++;
	return (i);
}

//si on a pas d'argument on print l'env trié en alphabetique
