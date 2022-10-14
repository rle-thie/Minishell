/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:35:48 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/14 16:09:26 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*path(char *cmd)
{
	char	*env_path;
	char	*tmp_path;
	char	*path;

	env_path = find_path_str();
	tmp_path = make_path(ft_split(env_path, ':'), cmd);
	if (tmp_path)
	{
		path = ft_malloc((sizeof(*path) * ft_strlen(tmp_path) + 1), &g_data);
		ft_strlcpy(path, tmp_path, ft_strlen(tmp_path) + 1);
		free(tmp_path);
		return (path);
	}
	return (NULL);
}

char	*make_path(char **test_path, char *cmd)
{
	char	*tmp_cmd;
	char	*tmp_path;
	int		i;

	i = 0;
	tmp_path = NULL;
	tmp_cmd = ft_strjoin("/", cmd);
	while (test_path[i])
	{
		if (tmp_path)
			free(tmp_path);
		tmp_path = exec_path_test(tmp_cmd, test_path[i]);
		if (!access(tmp_path, F_OK | X_OK))
			break ;
		//free(tmp_path);
		i++;
	}
	// if (test_path[i])
	// {
	// 	free(tmp_path);
	// 	return (NULL);
	// }
	free(tmp_cmd);
	free_split(test_path);
	return (tmp_path);
}

char	*exec_path_test(char *cmd, char *path)
{
	char	*test_path;

	test_path = ft_strjoin(path, cmd);
	return (test_path);
}

void	free_split(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		if (paths[i])
			free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
}

char	*find_path_str(void)
{
	t_env	*head;

	head = g_data.env_head;
	while (head->next)
	{
		if (!ft_strncmp(head->name, "PATH", 5))
			return (head->str);
		head = head->next;
	}
	if (head)
		if (!ft_strncmp(head->name, "PATH", 5))
			return (head->str);
	return (NULL);
}
