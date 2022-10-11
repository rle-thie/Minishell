/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:05:29 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/10 14:06:10 by ldevy            ###   ########.fr       */
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

// #include "parsing.h"

# include "built_in.h"

//init de l'environnement en liste chainee
# include "init_env.h"

//exec 
# include "exec.h"

//data en global var
extern t_data	g_data;

#endif