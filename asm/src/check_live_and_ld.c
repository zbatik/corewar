/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live_and_ld.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:16:01 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 13:05:54 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				check_live(char **args, t_main *var)
{
	char		**par;

	print_live_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_live_error_2(var, par);
	if (!is_direct(*par, var))
	{
		ft_printf(2, lr, "Error: invalid argument.\n");
		ft_printf(2, lr, "Expected:\tlive [T_DIRECT].\n");
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

int				check_ld(char **args, t_main *var)
{
	char		**par;

	print_ld_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_ld_error_2(var, par);
	if ((!is_direct(par[0], var) && !is_indirect(par[0], var))
			|| !is_register(par[1], var))
	{
		ft_printf(2, lr, "Error: invalid arguments.\n");
		ft_printf(2, lr, "Expected:\tld [T_DIRECT | T_IND], [T_REG].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}
