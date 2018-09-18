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
t_bool	parse_listinfo(t_main *var)
{
	t_input *tmp;
	int		count;

	tmp = var->input;
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
				if (inst_to_enum(tmp->line) == 16)
					tmp->param_encoding = 64;
				if (tmp->param_encoding != 0)
				{
					tmp->byte_count++;
					count++;
				}
			}
			if (is_label(tmp->line) == TRUE)
			{
				tmp->byte_count = count;
				tmp->is_label = TRUE;
			}
		}
		tmp = tmp->next;
	}
	tmp = var->input;
	var->total_player_size = count;
	if(count > CHAMP_MAX_SIZE)
	{
		ft_putstr("ERROR: TOO big a player\n");
		exit (1);
	}
	count = 0;
	while (tmp != NULL)
	{
		if (is_wsstring(tmp->line) == FALSE)
		{
			if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
				&& is_comment(tmp->line) == FALSE )
			{
				gen_bytecode(var->input, tmp, count);
				count += tmp->byte_count;
			}
		}
		tmp = tmp->next;
	}
	return(TRUE);
}
