/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevy <ldevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/03 15:17:21 by rle-thie         ###   ########.fr       */
=======
/*   Updated: 2022/10/11 15:10:15 by ldevy            ###   ########.fr       */
>>>>>>> 22f80775a7046dccb590c05efd3d061e0741adb2
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_data g_data;

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
// ft_garb_free_all(data);
// 	return (0);
// }

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	data = init_all(envp);

	envp = envp;
	while (1)
	{
		str = readline("Minishell : ");
		lexer(str, data);
		break;
	}
	str=str;
	ft_garb_free_all(data);
	return (0);
}

// int main(int ac, char const **av, char **envp)
// {
// 	t_data *data;
// 	char *str="";

// 	(void)ac;
// 	(void)av;
// 	data = init_all(envp);

// 	envp = envp;
// 	while (1)
// 	{
// 		// str = readline("Minishell : ");
// 		lexer(str, data);
// 		break;
// 	}
// 	str=str;
// 	ft_garb_free_all(data);
// 	return (0);
// }
