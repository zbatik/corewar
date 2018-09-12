/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:39:32 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/12 12:21:51 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

/*TODO
**At the end of the main process delete memory
** input_del needs to be tested
** After file_tolist all error handling (is_validfile)
** Upadate byte count will require pass_param function
** After Error handling we need to run function that
** 			popuates the input with byte_size instuction_code etc 
**	Write to file which will take all the info in in_head and print its bytes
*/
int main(int ac, char *av[])
{
	t_main var;

	if (ac > 1)
	{
		store_input(&var, av[1]);
		error_check_data(&var);
		while (var.temp_input != NULL)
		{
			ft_putnbr(var.temp_input->line_no);
			ft_putstr(" - ");
			ft_putendl(var.temp_input->line);
			var.temp_input = var.temp_input->next;
		}
	/*	if (parse_listinfo(var.input) == TRUE)
		{
			print_cor(var.input, av[1]);
		}
		else
			ft_putendl("ERROR: error in file");*/
	}
	else
	{
		ft_putendl("Usage:\n./asm file_name[.s] ...");
		return (0);
	}
}
