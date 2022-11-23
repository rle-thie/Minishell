/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_ex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:51:36 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/23 16:22:28 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_builtin	*init_builtin(void)
{
	t_builtin	*built_point;

	built_point = ft_malloc(sizeof(t_builtin) * 8, &g_data);
	built_point[0].nom = "echo";
	built_point[0].ptr_fct = my_echo;
	built_point[1].nom = "cd";
	built_point[1].ptr_fct = my_cd;
	built_point[2].nom = "pwd";
	built_point[2].ptr_fct = my_pwd;
	built_point[3].nom = "export";
	built_point[3].ptr_fct = my_export;
	built_point[4].nom = "unset";
	built_point[4].ptr_fct = my_unset;
	built_point[5].nom = "env";
	built_point[5].ptr_fct = my_env;
	built_point[6].nom = "exit";
	built_point[6].ptr_fct = my_exit;
	built_point[7].nom = NULL;
	built_point[7].ptr_fct = NULL;
	return (built_point);
}

int	is_builtin(t_cmd *cmd)
{
	int			i;
	int			buff;
	t_builtin	*tab;

	tab = init_builtin();
	i = 0;
	if (!cmd->cmd_name)
		return (0);
	while (tab[i].nom)
	{
		buff = ft_strlen(cmd->cmd_name) + ft_strlen(tab[i].nom);
		if (!ft_strncmp(cmd->cmd_name, tab[i].nom, buff))
		{
			ft_free(tab, &g_data);
			return (1);
		}
		i++;
	}
	ft_free(tab, &g_data);
	return (0);
}

int	builtin_exec(t_cmd *cmd)
{
	int			i;
	int			buff;
	t_builtin	*tab;
	char		**args;

	if (!cmd->cmd_name)
		return (0);
	args = cmd->flags_and_args;
	tab = init_builtin();
	i = 0;
	while (tab[i].nom)
	{
		buff = ft_strlen(cmd->cmd_name) + ft_strlen(tab[i].nom);
		if (!ft_strncmp(cmd->cmd_name, tab[i].nom, buff))
			return (builtin_exec_two(cmd, tab, args, i));
		i++;
	}
	ft_free(tab, &g_data);
	return (0);
}

int	builtin_exec_two(t_cmd *cmd, t_builtin *tab, char **args, int i)
{
	int	ret;
	int	fd;

	fd = redir_pipe(NULL, cmd);
	if (fd == -1)
	{
		ft_free(tab, &g_data);
		return (1);
	}
	ret = (*tab[i].ptr_fct)(&args[1]);
	dup2(STDIN_FILENO, fd);
	ft_free(tab, &g_data);
	return (ret);
}
