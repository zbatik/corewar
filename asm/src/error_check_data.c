/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:21:38 by emaune            #+#    #+#             */
/*   Updated: 2018/09/11 13:26:31 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		error_check_data(t_main *var)
{
	t_input *a;

	a = var->input;
	while (a)
	{
		error_check_line(var, a->line, a->line_no);
		a = a->next;
		var->temp_input = a;
	}
	var->temp_input = var->input;
}
