/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:24:50 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/26 13:10:25 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	input_del(t_input **ahead)
{
	t_input	*tmp;
	t_input	*prev;

	if (ahead != NULL && (tmp = *ahead) != NULL)
	{
		while (tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev->line);
			free(prev);
		}
		*ahead = NULL;
		free(ahead);
	}
}
