/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-thie <rle-thie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:19:22 by rle-thie          #+#    #+#             */
/*   Updated: 2021/12/13 13:22:50 by rle-thie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*alst;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	alst = NULL;
	while (lst)
	{
		new = ft_lstnew(lst->content);
		if (!new)
		{
			ft_lstclear(&alst, del);
			return (NULL);
		}
		new->content = f(new->content);
		ft_lstadd_back(&alst, new);
		lst = lst->next;
	}
	return (alst);
}
