/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_st_and_add.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:26:28 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 13:01:50 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				check_st(char **args, t_main *var)
{
	char		**par;

	print_st_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_st_error_2(var, par);
	if ((!is_register(par[1], var) && !is_indirect(par[1], var))
			|| !is_register(par[0], var))
	{
		ft_printf(2, lr, "Error: invalid arguments.\n");
		ft_printf(2, lr, "Expected:\tst [T_REG], [T_IND | T_REG].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}

int				check_add(char **args, t_main *var)
{
	char		**par;

	print_add_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_add_error_2(var, par);
	if (!is_register(par[0], var) || !is_register(par[1], var)
			|| !is_register(par[2], var))
	{
		ft_printf(2, lr, "Error: invalid arguments.\n");
		ft_printf(2, lr, "Expected:\tadd [T_REG], [T_REG], [T_REG].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		exit(EXIT_FAILURE);
	}
	return (1);
}
