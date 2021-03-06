/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_live_error_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 11:58:35 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 12:00:11 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_live_error_1(t_main *var, char **args)
{
	if (!args[1])
	{
		ft_printf(2, lr, "Error: mnemonic was unaccompanied by arguments.\n");
		ft_printf(2, lr, "Expected:\tlive [T_DIRECT].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
}
