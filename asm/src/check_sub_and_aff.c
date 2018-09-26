/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_add_and_sub.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:28:10 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 13:06:57 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				check_aff(char **args, t_main *var)
{
	char		**par;

	print_aff_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_aff_error_2(var, par);
	if (!is_register(*par, var))
	{
		ft_printf(2, lr, "Error: invalid argument.\nExpected:\taff [T_REG].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		free_split(par);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}

int				check_sub(char **args, t_main *var)
{
	char		**par;

	print_sub_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_sub_error_2(var, par);
	if (!is_register(par[0], var) || !is_register(par[1], var)
			|| !is_register(par[2], var))
	{
		ft_printf(2, lr, "Error: invalid arguments.\nExpected:\tsub [T_REG], ");
		ft_printf(2, lr, "[T_REG], [T_REG].\nGot:\t\t\"%s\" - line #%d\n",
				var->temp_input->line, var->temp_input->line_no);
		free_split(par);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}
