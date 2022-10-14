/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:05:29 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/14 12:15:27 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>

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

//data en global var
extern t_data	g_data;

#endif