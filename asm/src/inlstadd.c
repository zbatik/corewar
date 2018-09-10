/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inlstadd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:07:02 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/07 14:07:03 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	inlstadd(t_input **ahead, t_input *elem)
{
	t_input *tmp;

	tmp = *ahead;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	elem->next = NULL;
}
