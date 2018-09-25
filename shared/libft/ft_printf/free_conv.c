/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 14:34:55 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 11:36:46 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		free_conv(t_conv *c)
{
	t_conv 	*temp;
	t_conv	*prev;

	temp = c;
	while (tmp)
	{
		prev = tmp;
		temp = temp->next;
		ft_strdel(&prev->str);
		free(prev);
	}
}
