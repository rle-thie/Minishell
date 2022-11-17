/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:39:47 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/15 15:51:08 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*special_path(char *str)
{
	char	*home;
	char	*ret;

	home = get_home();
	ret = ft_strdup_gc(home, &g_data);
	ret = ft_strjoin_gc(ret, str, &g_data);
	return (ret);
}

int	my_cd(char **cmd)
{
	int		dir_ret;

	if (nb_args(cmd) > 1)
		return (ft_cd_error("", 1));
	if (!cmd[0] || ((cmd[0][0] == '~' && ft_strlen(cmd[0]) == 1) || !cmd[0][0]))
	{
		if (get_home() == NULL)
			return (ft_cd_error("", 2));
		dir_ret = chdir(get_home());
	}
	else if (cmd[0][0] == '~')
	{
		if (get_home() == NULL)
			return (ft_cd_error("", 2));
		dir_ret = chdir(special_path(&(cmd[0][1])));
	}
	else
		dir_ret = chdir(cmd[0]);
	if (dir_ret != 0)
		return (ft_cd_error("", errno));
	else
		change_pwds();
	return (EXIT_SUCCESS);
}

char	*get_home(void)
{
	t_env	*head;

	head = g_data.env_head;
	while (head->next)
	{
		if (!ft_strncmp(head->name, "HOME", 5))
			return (head->str);
		head = head->next;
	}
	if (head)
		if (!ft_strncmp(head->name, "HOME", 5))
			return (head->str);
	return (NULL);
}

void	change_pwds(void)
{
	t_env	*oldpwd;
	t_env	*pwd;
	char	*temp;

	temp = getcwd((char *) NULL, 0);
	oldpwd = find_cd_link("OLDPWD");
	pwd = find_cd_link("PWD");
	ft_free(oldpwd->str, &g_data);
	oldpwd->str = ft_malloc(sizeof(*(pwd->str)) * ft_strlen(pwd->str), &g_data);
	ft_strlcpy(oldpwd->str, pwd->str, ft_strlen(pwd->str));
	ft_free(pwd->str, &g_data);
	pwd->str = ft_malloc(sizeof(*temp) * ft_strlen(temp), &g_data);
	ft_strlcpy(pwd->str, temp, ft_strlen(temp));
	free(temp);
}

t_env	*find_cd_link(char *str)
{
	t_env	*head;

	head = g_data.env_head;
	while (head->next)
	{
		if (!ft_strncmp(head->name, str, ft_strlen(str)))
			return (head);
		head = head->next;
	}
	if (head)
		if (!ft_strncmp(head->name, str, ft_strlen(str)))
			return (head);
	return (NULL);
}
