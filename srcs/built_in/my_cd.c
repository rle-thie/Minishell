/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:39:47 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/31 21:11:06 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_cd_error(char *str, int e)
{
	(void)str;
	(void)e;
	ft_putstr_fd("bash: cd: ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

int	my_cd(char **cmd)
{
	int		dir_ret;

	if (!cmd[0] || ((cmd[0][0] == '~' && ft_strlen(cmd[0]) == 1) || !cmd[0][0]))
		dir_ret = chdir(get_home());
	else
		dir_ret = chdir(cmd[0]);
	if (dir_ret != 0)
	{
		ft_cd_error("lol", errno);
		return (errno);
	}
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
//PWD ??
//OLDPWD
//quand on fait un cd on save le directory avant le dernier cd 
// je crois qu'il me faut l'env dans une liste chainer pour pop et unpop des bails
// et pouvoir consulter simplement les bails