/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_xor_and_zjmp.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:30:31 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 13:16:55 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				check_xor(char **args, t_main *var)
{
	char		**par;

	print_xor_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_xor_error_2(var, par);
	if ((!is_register(par[0], var) && !is_direct(par[0], var)
				&& !is_indirect(par[0], var))
			|| (!is_register(par[1], var) && !is_direct(par[1], var)
				&& !is_indirect(par[1], var))
			|| !is_register(par[2], var))
	{
		ft_printf(2, lr, "Error: invalid arguments.\nExpected:\txor [T_REG | ");
		ft_printf(2, lr, "T_DIR | T_IND], [T_REG | T_DIR | T_IND], [T_REG].\n");
		ft_printf(2, lr, "Got: \"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		free_split(par);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}

int				check_zjmp(char **args, t_main *var)
{
	char		**par;

	print_zjmp_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_zjmp_error_2(var, par);
	if (!is_direct(*par, var))
	{
		ft_printf(2, lr, "Error: invalid argument.\n");
		ft_printf(2, lr, "Expected:\tzjmp [T_DIRECT].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		free_split(par);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}
