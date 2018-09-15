/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_listinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:27:06 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/07 10:27:07 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>
/**
**TODO:
**	Loop through the list and record the following:
**	if its a label assign the current byte count to byte_count
** 	if its an instruction generate its byte code and append the count
**	if the total count at the end is larger than the max return FALSE
*/
t_bool	parse_listinfo(t_input *ahead)
{
	t_input *tmp;
	int		count;

	tmp = ahead;
	count = 0;
	while (tmp != NULL)
	{
		if (is_wsstring(tmp->line) == FALSE)
		{
			if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
				&& is_comment(tmp->line) == FALSE )
			{
				count += instruction_byte_size(tmp);
				tmp->param_encoding = string_to_encoding(tmp->args);
			}
			if (is_label(tmp->line) == TRUE)
			{
				tmp->byte_count = count;
				tmp->is_label = TRUE;
			}
		}
		tmp = tmp->next;
	}
	tmp = ahead;
	count = 0;
	while (tmp != NULL)
	{
		if (is_wsstring(tmp->line) == FALSE)
		{
			if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
				&& is_comment(tmp->line) == FALSE )
			{
				count += tmp->byte_count;
				gen_bytecode(ahead, tmp, count);
			}
		}
		tmp = tmp->next;
	}
	return(TRUE);
}
