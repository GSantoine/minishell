/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recarlie <recarlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:59:41 by recarlie          #+#    #+#             */
/*   Updated: 2022/03/28 15:28:01 by recarlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Create a copy of a chained list then apply F function to every
 * element in the copy and delete it using Del function.
 * 
 * @param lst List.
 * @param f Function applied to every element.
 * @param del Function destroying elements of the old list.
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*lst_ptr;

	if (!lst)
		return (NULL);
	tmp = ft_lstnew((*f)(lst->content));
	if (!tmp)
	{
		ft_lstclear(&tmp, del);
		return (NULL);
	}
	lst_ptr = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew((*f)(lst->content));
		if (!tmp)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (lst_ptr);
}
