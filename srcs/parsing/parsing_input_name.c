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
		if (!ft_strcmp(head->name, str))
			return (head);
		head = head->next;
	}
	if (head)
		if (!ft_strcmp(head->name, str))
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

char	*input_name(void)
{
	char	s[1024];
	char	*cwd;
	char	*prompt;
	char	*user;
	char	*home;

	getcwd(s, sizeof(s));
	cwd = ft_strdup_gc(s, &g_data);
	if (!find_env_var("HOME") || !find_env_var("USER") || !cwd)
		return ("minishell : ");
	prompt = ft_calloc(sizeof(char) * 1, &g_data);
	user = ft_strdup_gc(add_expand("USER"), &g_data);
	home = ft_strdup_gc(add_expand("HOME"), &g_data);
	if (!user || !home || !&g_data.env || !cwd)
		return (prompt_without_env());
	prompt = ft_strjoin_gc(prompt, user, &g_data);
	prompt = ft_strjoin_gc(prompt, "@minishell", &g_data);
	prompt = ft_strjoinchar_gc(prompt, ':', &g_data);
	prompt = ft_strjoin_gc(prompt, cwd, &g_data);
	prompt = ft_strjoin_gc(prompt, "$ ", &g_data);
	return (prompt);
}
