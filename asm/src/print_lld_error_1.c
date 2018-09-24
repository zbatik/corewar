/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lld_error_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:23:15 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 15:25:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_lld_error_1(t_main *var, char **args)
{
	if (!args[1])
	{
		ft_printf(2, lr, "Error: mnemonic was unaccompanied by arguments.\n");
		ft_printf(2, lr, "Expected:\tlld [T_DIRECT | T_IND], [T_REG].\n");
		ft_printf(2, lr, "Got:\t\t \"%s\" - line #%d", var->temp_input->line,
				var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
}
