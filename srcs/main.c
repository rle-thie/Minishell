/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 19:03:24 by rle-thie          #+#    #+#             */
/*   Updated: 2022/10/21 18:16:03 by rle-thie         ###   ########.fr       */
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

int main(int ac, char const **av, char **envp)
{
    char *str;
	
    (void)ac;
    (void)av;
    init_all(envp);

    while (1)
    {
        str = readline("Minishell : ");
		lexer(str, &g_data);
		// parser();
		g_data.cmd = NULL;
		g_data.token = NULL;
		break;
    }
	ft_garb_free_all(&g_data);
    // str=str;
    return (0);
}

// int	main(int ac, char **av, char **envp)
// {
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
// 	str=str;
// 	ft_garb_free_all(data);
// 	return (0);
// }

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
