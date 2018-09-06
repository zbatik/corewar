/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:39:32 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/06 15:34:02 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

/*
int		is_validarg(char *s)
{
	
}

void	parse_listtolabel(t_dblist **head)
{
	// if its a label add to it the amout of bytes "read"
	// this is going to generate the absolute byte position
	//check parameter syntax


}

void	convert_to_byte(t_dblist **head)
{

} */
/*TODO
**At the end of the main process delete memory
** input_del needs to be tested
**
*/
int main(int ac, char *av[])
{
	t_input	*in_head;
	t_input	*tmp;

	(void) tmp;
	if (ac > 1)
	{
		in_head = file_tolist(av[1]);
		tmp = in_head;
		while (tmp != NULL)
		{
			ft_putnbr(tmp->line_no);
			ft_putstr(": ");
			ft_putendl(tmp->line);
			tmp = tmp->next;
		}
		//input_del(&in_head);
	}
	else
	{
		ft_putendl("Usage:\n./asm file_name[.s] ...");
		return (0);
	}
}
