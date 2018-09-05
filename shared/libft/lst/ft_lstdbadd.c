/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:22:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/29 15:24:54 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdbadd(t_dblist **dblst, t_dblist *new_node)
{
	new_node->prev = *dblst;
	if (*dblst != NULL)
		(*dblst)->next = new_node;
	*dblst = new_node;
}
