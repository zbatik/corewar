/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_no_par.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:04:34 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 14:07:07 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			print_error_and_no_par(t_main *var, char **args)
{
	if (!args[1])
	{
		ft_printf(2, lr, "Error: mnemonic was unaccompanied by arguments.\n");
		ft_printf(2, lr, "Expected: and [T_REG | T_DIR | T_IND], [T_REG],");
		ft_printf(2, lr, "[T_REG | T_DIR | T_IND], [T_REG].\nGot: \"%s\"",
				var->temp_input->line);
		ft_printf(2, lr, " - line #%d\n", var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		exit(EXIT_FAILURE);
	}
}
