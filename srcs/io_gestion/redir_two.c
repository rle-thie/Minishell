/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:52:51 by ldevy             #+#    #+#             */
/*   Updated: 2022/11/23 16:16:53 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	err_msg_rd(char *str, t_cmd *cmd)
{
	printf("bash: %s : %s", str, strerror(errno));
	if (is_builtin(cmd) && cmd_number() == 1)
		return (1);
	exit (1);
}
