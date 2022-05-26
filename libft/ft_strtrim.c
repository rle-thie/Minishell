/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:35:33 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/06 19:05:13 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(const char str, char const *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == str)
			return (1);
		i++;
	}
	return (0);
}

static char	*fill_tab(size_t start, size_t end, char *tab, const char *s1)
{
	size_t		i;

	i = 0;
	while (start < end)
	{
		tab[i++] = s1[start++];
	}
	tab[i] = '\0';
	return (tab);
}

/*static void	exeption(char *tab)
{
	tab = malloc(sizeof(char) * 1);
		if (!tab)
			return (NULL);
		tab[0] = '\0';
}*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	char		*tab;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_charset(s1[start], set))
		start++;
	if (start == ft_strlen(s1))
	{
		tab = malloc(sizeof(char) * 1);
		if (!tab)
			return (NULL);
		tab[0] = '\0';
		return (tab);
	}
	while (s1[end] && is_charset(s1[end], set))
		end--;
	end = (end - (ft_strlen(s1) - 1)) * -1;
	tab = malloc(sizeof(char) * (ft_strlen(s1) - (start + end) + 1));
	if (!tab)
		return (NULL);
	return (fill_tab(start, ft_strlen(s1) - end, tab, s1));
}

/*int		main(void)
{
	char *tab = "aaaafaaaa";
	char *set = "ac";

	printf("%s", ft_strtrim(tab, set));
	//ft_strtrim(tab, set);
	return (0);
}*/
