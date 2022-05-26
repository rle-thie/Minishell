/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:05:27 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/08 14:04:35 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static t_list	*list_add(t_list *list, char *content)
// {
// 	t_list	*tmp;

// 	tmp = malloc(sizeof(t_list));
// 	if (tmp)
// 	{
// 		tmp->content = content;
// 		tmp->next = list;
// 	}
// 	return (tmp);

// static void	print_list(t_list *list)
// {
// 	while (list)
// 	{
// 		ft_putstr(list->content);
// 		list = list->next;
// 	}
// }

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = NULL;
	tmp = malloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}

// int	main(void)
// {
// 	t_list	*list;
// 	list = NULL;
// 	list = list_add(list, "aaa\n");
// 	list = list_add(list, "bbb\n");
// 	list = list_add(list, "ccc\n");
// 	print_list(list);
// 	if (!list)
// 		printf("c'est vide");
// 	return (0);
// }
