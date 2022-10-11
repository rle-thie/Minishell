/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:11:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/07 12:32:24 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_print_error(char *str)
{
	ft_putstr_fd("bash: export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
	//exit status failure
}

void	my_export(char **cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		env_order();
	while (cmd[i])
	{
		if (!void_arg_export_checker(cmd[i]))
			ft_print_error(cmd[i]);
		i++;
		//exit status success
	}
}

int	void_arg_export_checker(char *str)
{
	int	i;

	i = 0;
	if (!ft_strchr(str, '=') || (!ft_isalpha(str[i]) && str[i] != '_'))
		return (0);
	i++;
	while (str[i] != '=')
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	make_node(str);
	return (1);
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
