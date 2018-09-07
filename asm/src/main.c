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

/*TODO
**At the end of the main process delete memory
** input_del needs to be tested
** After file_tolist all error handling (is_validfile)
** After Error handling we need to run function that
** 			popuates the input with byte_size instuction_code etc 
**	Write to file which will take all the info in in_head and print its bytes
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
			ft_putchar(':');
			ft_putendl(tmp->line);
			tmp = tmp->next;
		}
		/*if (is_validfile(in_head) == TRUE)
		{
			if (parse_listinfo(in_head) == TRUE)
			{
				print_cor(in_head, av[1]);
			}
		}
		else
			ft_putendl("ERROR: error in file"); */
	}
	else
	{
		ft_putendl("Usage:\n./asm file_name[.s] ...");
		return (0);
	}
}
