/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_or.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:29:17 by emaune            #+#    #+#             */
/*   Updated: 2018/09/13 12:51:20 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		check_and(char **args, t_main *var)
{
	int         i;
	char        **par;

	i = 0;
	if (!args[1])
	{
		ft_putendl("\x1b[31;1mError: mnemonic was unaccompanied by arguments.\nExpected: and [T_REG | T_DIR | T_IND], [T_REG], [T_REG | T_DIR | T_IND], [T_REG].");
		ft_putstr("Got: \"");
		ft_putstr(var->temp_input->line);
		ft_putstr("\" - line #");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free split and list and par;
	}
	par = ft_strsplit(args[1], ',');
	while (par[i])
		i++;
	if (i > 3 || i < 3)
	{
		ft_putendl("\x1b[31;1mError: too many/too few arguments.\nExpected: and [T_REG | T_DIR | T_IND], [T_REG | T_DIR | T_IND], [T_REG].");
		ft_putstr("Got: \"");
		ft_putstr(var->temp_input->line);
		ft_putstr("\" - line #");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free split and list and par;

	}
	if ((!is_register(par[0], var) && !is_direct(par[0], var) && !is_indirect(par[0], var))
			|| (!is_register(par[1], var) && !is_direct(par[1], var) && !is_indirect(par[1], var))
			|| !is_register(par[2], var))
	{
		ft_putendl("\x1b[31;1mError: invalid arguments.\nExpected: and [T_REG | T_DIR | T_IND], [T_REG | T_DIR | T_IND], [T_REG].");
		ft_putstr("Got: \"");
		ft_putstr(var->temp_input->line);
		ft_putstr("\" - line #");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free  split and list and par
	}
	free_split(par);
	return (1);
}

int		check_or(char **args, t_main *var)
{
	int         i;
	char        **par;

	i = 0;
	if (!args[1])
	{
		ft_putendl("\x1b[31;1mError: mnemonic was unaccompanied by arguments.\nExpected: or [T_REG | T_DIR | T_IND], [T_REG], [T_REG | T_DIR | T_IND], [T_REG].");
		ft_putstr("Got: \"");
		ft_putstr(var->temp_input->line);
		ft_putstr("\" - line #");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free split and list and par;
	}
	par = ft_strsplit(args[1], ',');
	while (par[i])
		i++;
	if (i > 3 || i < 3)
	{
		ft_putendl("\x1b[31;1mError: too many/too few arguments.\nExpected: or [T_REG | T_DIR | T_IND], [T_REG | T_DIR | T_IND], [T_REG].");
		ft_putstr("Got: \"");
		ft_putstr(var->temp_input->line);
		ft_putstr("\" - line #");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free split and list and par;

	}
	if ((!is_register(par[0], var) && !is_direct(par[0], var) && !is_indirect(par[0], var))
			|| (!is_register(par[1], var) && !is_direct(par[1], var) && !is_indirect(par[1], var))
			|| !is_register(par[2], var))
	{
		ft_putendl("\x1b[31;1mError: invalid arguments.\nExpected: or [T_REG | T_DIR | T_IND], [T_REG | T_DIR | T_IND], [T_REG].");
		ft_putstr("Got: \"");
		ft_putstr(var->temp_input->line);
		ft_putstr("\" - line #");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free  split and list and par
	}
	return (1);

}
