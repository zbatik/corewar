/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbgotobottom.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 13:14:11 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/06 13:27:58 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdbtotop(t_dblist **list)
{
	if (*list == NULL)
		return ;
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
