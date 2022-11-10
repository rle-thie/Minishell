/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 02:30:39 by rle-thie          #+#    #+#             */
/*   Updated: 2022/11/10 03:18:59 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_env	*find_env_var(char *str)
{
	t_env	*head;

	head = g_data.env_head;
	while (head->next)
	{
		if (!ft_strncmp(head->name, str, ft_strlen(str)))
			return (head);
		head = head->next;
	}
	if (head)
		if (!ft_strncmp(head->name, str, ft_strlen(str)))
			return (head);
	return (NULL);
}

// virer cmd ($) et remplacer cmd.next.str par la valeur de la variable d'env
static char	*add_expand(char *var_name)
{
	t_env	*lst;

	lst = find_env_var(var_name);
	var_name = lst->str;
	return (var_name);
}

char	*prompt_without_env(void)
{
	char	*prompt;
	char	cwd[1024];

	getcwd(cwd, sizeof(cwd));
	prompt = ft_strdup_gc(cwd, &g_data);
	prompt = ft_strjoin_gc(prompt, "$ ", &g_data);
	return (prompt);
}

// char	*home_prompt(char *prompt, char *cwd, char *home, t_data *data)
// {
// 	if (!ft_strncmp(cwd, home, ft_strlen(home)))
// 	{
// 		if (ft_getenv(data->env, "HOME"))
// 			prompt = ft_strjoin_char(prompt, '~', data);
// 		cwd = ft_substr(cwd, ft_strlen(home), ft_strlen(cwd), data);
// 		prompt = ft_strjoin(prompt, cwd, data);
// 	}
// 	else
// 		prompt = ft_strjoin(prompt, cwd, data);
// 	ft_free(cwd, data);
// 	return (prompt);
// }

// char	*get_prompt(t_data *data, char **envp)
// {
// 	char	s[1024];
// 	char	*cwd;
// 	char	*prompt;
// 	char	*user;
// 	char	*home;

// 	getcwd(s, sizeof(s));
// 	cwd = ft_strdup_gc(s, &g_data);
// 	user = ft_strdup_gc(ft_getenv(data->env, "USER"), &g_data);
// 	home = ft_strdup(ft_getenv(data->env, "HOME"), &g_data);
// 	if (!user || !home || !envp[0])
// 		return (prompt_without_env(data));
// 	prompt = ft_strdup("\001\033[1;31m\002", data);
// 	prompt = ft_strjoin(prompt, user, data);
// 	prompt = ft_strjoin(prompt, "@minishell\001\033[0m\002", data);
// 	prompt = ft_strjoin_char(prompt, ':', data);
// 	prompt = ft_strjoin(prompt, "\001\033[1;34m\002", data);
// 	prompt = home_prompt(prompt, cwd, home, data);
// 	prompt = ft_strjoin(prompt, "\001\033[0m\002", data);
// 	prompt = ft_strjoin(prompt, "$ ", data);
// 	return (prompt);
// }

char	*input_name(void)
{
	char	s[1024];
	char	*cwd;
	char	*prompt;
	char	*user;
	char	*home;
	char	dpoint[2];

	dpoint[0] = ':';
	dpoint[1] = '\0';
	prompt = ft_calloc(sizeof(char) * 2, &g_data);
	prompt[0] = ' ';
	getcwd(s, sizeof(s));
	cwd = ft_strdup_gc(s, &g_data);
	user = ft_strdup_gc(add_expand("USER"), &g_data);
	home = ft_strdup_gc(add_expand("HOME"), &g_data);
	if (!user || !home || !&g_data.env || !cwd)
		return (prompt_without_env());
	// prompt = ft_strdup_gc("\001\033[1;31m\002", &g_data);
	prompt = ft_strjoin_gc(prompt, user, &g_data);   
	prompt = ft_strjoin_gc(prompt, "@minishell", &g_data);
	prompt = ft_strjoin_gc(prompt,  dpoint, &g_data);
	prompt = ft_strjoin_gc(prompt, cwd, &g_data);
	prompt = ft_strjoin_gc(prompt, "$ ", &g_data);
	return (del_first_space(prompt));
}