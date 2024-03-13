/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarac <yunusemresarac@yaani.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 07:47:49 by ysarac            #+#    #+#             */
/*   Updated: 2023/10/24 20:43:09 by ysarac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*begin;

	if (lst == NULL || f == NULL)
	{
		return (NULL);
	}
	begin = 0;
	while (lst)
	{
		newlist = ft_lstnew(f(lst->content));
		if (!newlist)
		{
			ft_lstclear(&begin, del);
			return (NULL);
		}
		ft_lstadd_back(&begin, newlist);
		lst = lst->next;
	}
	return (begin);
}
