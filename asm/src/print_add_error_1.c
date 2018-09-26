/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add_error_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:47:55 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 12:48:37 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_add_error_1(t_main *var, char **args)
{
	if (!args[1])
	{
		ft_printf(2, lr, "Error: mnemonic was unaccompanied by arguments.\n");
		ft_printf(2, lr, "Expected:\tadd [T_REG], [T_REG], [T_REG].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		exit(EXIT_FAILURE);
	}
}
