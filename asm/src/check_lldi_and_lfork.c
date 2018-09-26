/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lldi_and_lfork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:44:08 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 13:17:37 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				check_lldi(char **args, t_main *var)
{
	char		**par;

	print_lldi_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_lldi_error_2(var, par);
	if ((!is_register(par[0], var) && !is_direct(par[0], var)
				&& !is_indirect(par[0], var))
			|| (!is_register(par[1], var) && !is_direct(par[1], var))
			|| !is_register(par[2], var))
	{
		ft_printf(2, lr, "Error: invalid arguments.\nExpected:\tlldi ");
		ft_printf(2, lr, "[T_REG | T_DIR | T_IND], [T_REG | T_DIR],[T_REG].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input);
		free_split(par);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}

int				check_lfork(char **args, t_main *var)
{
	char		**par;

	print_lfork_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_lfork_error_2(var, par);
	if (!is_direct(*par, var))
	{
		ft_printf(2, lr, "Error: invalid argument.\n");
		ft_printf(2, lr, "Expected:\tlfork [T_DIRECT]\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n",
				var->temp_input->line, var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		free_split(par);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}
