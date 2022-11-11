/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:05:29 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 16:20:49 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _GNU_SOURCE
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include "../libft/libft.h"

// include files
# include "struct.h"
# include "init.h"
# include "parsing.h"
# include "utils.h"

// #include "parsing.h"

# include "built_in.h"

//exec 
# include "exec.h"

//io_gestion
# include "io_gestion.h"

//data en global var
extern t_data	g_data;

#endif