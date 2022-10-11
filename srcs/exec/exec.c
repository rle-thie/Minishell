/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 13:35:48 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/10 18:20:45 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*path(char *str)
{
	char	*env_path;

	env_path = find_path_str();
	ft_split(env_path, ':');
	//partie test d'access
	if (!access(path, F_OK | X_OK)
	else 
		perror("error");
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
