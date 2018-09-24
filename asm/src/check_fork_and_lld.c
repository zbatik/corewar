/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork_and_lld.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:33:52 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 15:24:28 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_fork(char **args, t_main *var)
{
	int         i;
	char        **par;

	i = 0;
	print_fork_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	print_fork_error_2(var, par);
	if (!is_direct(*par, var))
	{
		ft_printf(2, lr, "Error: invalid argument.\n");
		ft_printf(2, lr, "Expected:\tfork [T_DIRECT].\n");
		ft_printf(2, lr, "Got:\t\t \"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		free_split(par);
		exit(EXIT_FAILURE);
	}
	free_split(par);
	return (1);
}

int			check_lld(char **args, t_main *var)
{
	int         i;
	char        **par;

	i = 0;
	print_lld_error_1(var, args);
	par = ft_strsplit(args[1], ',');
	while (par[i])
		i++;
	if (i > 2 || i < 2)
	{
		ft_putendl("\x1b[31;1mError: too many/too few arguments.\nExpected: lld [T_DIRECT | T_IND], [T_REG].");
		ft_putstr("Got: \"");
		ft_putstr(var->temp_input->line);
		ft_putstr("\" - line #");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free split and list and par;

	}
	if ((!is_direct(par[0], var) && !is_indirect(par[0], var)) || !is_register(par[1], var))
	{
		ft_putendl("\x1b[31;1mError: invalid arguments.\nExpected: lld [T_DIRECT | T_IND], [T_REG].");
		ft_putstr("Got: \"");
		ft_putstr(var->temp_input->line);
		ft_putstr("\" - line #");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free  split and list and par
	}
	return (1);
}
