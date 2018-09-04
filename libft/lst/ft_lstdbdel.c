/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 12:27:17 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/22 15:33:59 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdbdel(t_dblist **list)
{
	t_dblist *next;

	while (*list)
	{
		next = (*list)->next;
		ft_lstdbdelone(list);
		*list = next;
	}
	*list = NULL;
}
