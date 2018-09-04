/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 21:00:50 by zack              #+#    #+#             */
/*   Updated: 2018/06/12 13:25:38 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list_new;
	t_list *list_start;

	if (!lst || !f)
		return (NULL);
	list_new = f(lst);
	lst = lst->next;
	list_start = list_new;
	while (lst != NULL)
	{
		list_new->next = f(lst);
		lst = lst->next;
		list_new = list_new->next;
	}
	return (list_start);
}
