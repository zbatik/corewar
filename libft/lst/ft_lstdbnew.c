/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:36:42 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/29 15:25:27 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

t_dblist	*ft_lstdbnew(char *str, int n)
{
	t_dblist *new_list;

	new_list = (t_dblist*)malloc(sizeof(t_dblist));
	if (new_list == NULL)
		return (NULL);
	new_list->str = ft_strdup(str);
	new_list->n = n;
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}
