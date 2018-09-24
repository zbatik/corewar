/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:29:17 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 14:46:21 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_and(char **args, t_main *var)
{
	char        **par;

	print_error_and_no_par(var, args);
	par = ft_strsplit(args[1], ',');
	print_error_and_2(var, par);
	if ((!is_register(par[0], var) && !is_direct(par[0], var)
				&& !is_indirect(par[0], var))
			|| (!is_register(par[1], var) && !is_direct(par[1], var)
				&& !is_indirect(par[1], var))
			|| !is_register(par[2], var))
	{
		ft_printf(2, lr, "\x1b[31;1mError: invalid arguments.\nExpected: ");
		ft_printf(2, lr, "and [T_REG | T_DIR | T_IND], [T_REG | T_DIR |");
		ft_printf(2, lr, " [T_IND], [T_REG].\nGot:\"%s\" - line #%d\n",
				var->temp_input->line, var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}

int		check_or(char **args, t_main *var)
{
	int         i;
	char        **par;

	i = 0;
	print_or_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_or_error_2(var, par);
	if ((!is_register(par[0], var) && !is_direct(par[0], var)
				&& !is_indirect(par[0], var))
			|| (!is_register(par[1], var) && !is_direct(par[1], var)
				&& !is_indirect(par[1], var))
			|| !is_register(par[2], var))
	{
		ft_printf(2, lr, "Error: invalid arguments.\nExpected: or [T_REG]");
		ft_printf(2, lr, " | T_DIR | T_IND], [T_REG | T_DIR | T_IND], [T_REG].");
		ft_printf(2, lr, "\nGot: \"%s\" - line #%d", var->temp_input->line,
				var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		exit(EXIT_FAILURE);
	}
	return (1);

}
