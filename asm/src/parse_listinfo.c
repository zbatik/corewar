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

#include <asm.h>
#include <stdio.h>


void	gen_bytecode(t_input *elem)
{
	(void) elem;
}

t_bool	is_validfile(t_input *ahead)
{
	(void) ahead;
	return (TRUE);
}
/**
**TODO:
**Loop through the list and record the following:
**	if its a label assign the current byte count to byte_count
** 	if its an instruction generate its byte code and append the count
**	if the total count at the end is larger than the max return FALSE
*/
t_bool	parse_listinfo(t_input *ahead)
{
	t_input *tmp;
	t_byte	count;

	tmp = ahead;
	count = 0;
	if (tmp != NULL)
	{
		//if (tmp->is_label == FALSE)
		printf("%d\n",instruction_byte_size(tmp->line));
		/*if (tmp->is_label == TRUE)
			tmp->byte_count = count;
		else if (is_name(tmp->line) == FALSE && is_comment(tmp->line) == FALSE)
		{
			gen_bytecode(tmp);
		}*/
		tmp = tmp->next;
	}
	return(TRUE);
}
