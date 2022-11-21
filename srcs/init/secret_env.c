/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secret_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:01:45 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/21 18:09:24 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	spe_env(void)
{
	char	*path;
	char	*pwd;

	path = getcwd((char *) NULL, 0);
	pwd = ft_strjoin("PWD=", path);
	make_node("PATH=/usr/bin");
	make_node(pwd);
	free(pwd);
	return ;
}
