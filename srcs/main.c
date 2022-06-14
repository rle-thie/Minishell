/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/06/14 18:40:01 by ldevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// int main(int ac, char const **av, char **envp)
// {
// 	t_data *data;
// 	char *str;

// 	(void)ac;
// 	(void)av;
// 	data = init_all(envp);

// 	envp = envp;
// 	while (1)
// 	{
// 		str = readline("Minishell : ");
// 		lexer(str, data);
// 		break;
// 	}
// 	ft_garb_free_all(data);
// 	return (0);
// }

int	main(int ac, char **av, char **envp)
{
	t_data	*data;
	//char *str;

	(void)ac;
	(void)av;
	data = init_all(envp);
	my_env(&av[1], *data);
	return (0);
}
