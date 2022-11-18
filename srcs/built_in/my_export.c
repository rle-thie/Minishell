/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:11:37 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/17 19:24:00 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ft_print_error(char *str)
{
	ft_putstr_fd("bash: export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("': not a valid identifier\n", STDERR_FILENO);
}

int	my_export(char **cmd)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (nb_args(cmd) == 0)
	{
		env_order();
		return (EXIT_SUCCESS);
	}
	while (cmd[i])
	{
		if (!void_arg_export_checker(cmd[i]))
		{
			ft_print_error(cmd[i]);
			ret = 1;
		}
		i++;
	}
	return (ret);
}

int	void_arg_export_checker(char *str)
{
	int		i;
	char	*tmp;

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
	tmp = ft_malloc(find_signe(str) + 1, &g_data);
	ft_strlcpy(tmp, str, find_signe(str) + 1);
	if (find_cd_link(tmp))
		del_env_link(find_cd_link(tmp));
	make_node(str);
	ft_free(tmp, &g_data);
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
