/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:39:47 by ldevy             #+#    #+#             */
/*   Updated: 2022/10/03 17:01:08 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	my_cd(char *path, t_data data)
{
	if (!path)
		chdir(HOME);
	
}

//PWD ??
//OLDPWD
//quand on fait un cd on save le directory avant le dernier cd 
// je crois qu'il me faut l'env dans une liste chainer pour pop et unpop des bails
// et pouvoir consulter simplement les bails