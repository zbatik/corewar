/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fork_error_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:51:40 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 14:55:48 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_fork_error_1(t_main *var, char **args)
{
	if (!args[1])
	{
		ft_printf(2, lr, "Error: mnemonic was unaccompanied by arguments.\n");
		ft_printf(2, lr, "Expected: fork [T_DIRECT].\n");
		ft_printf(2, lr, "Got \"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
}
