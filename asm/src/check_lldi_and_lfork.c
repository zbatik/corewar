/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lldi_and_lfork.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:44:08 by emaune            #+#    #+#             */
/*   Updated: 2018/09/13 13:37:29 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_lldi(char **args, t_main *var)
{
   	int         i;
    char        **par;

    i = 0;
    if (!args[1])
    {
        ft_putendl("\x1b[31;1mError: mnemonic was unaccompanied by arguments.\nExpected: lldi [T_REG | T_DIR | T_IND], [T_REG | T_DIR], [T_REG].");
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
        ft_putendl("\x1b[31;1mError: too many/too few arguments.\nExpected: lldi [T_REG | T_DIR | T_IND], [T_REG | T_DIR], [T_REG].");
        ft_putstr("Got: \"");
        ft_putstr(var->temp_input->line);
        ft_putstr("\" - line #");
        ft_putnbr(var->temp_input->line_no);
        exit(EXIT_FAILURE);
        //free split and list and par;

    }
    if ((!is_register(par[0], var) && !is_direct(par[0], var) && !is_indirect(par[0], var))
            || (!is_register(par[1], var) && !is_direct(par[1], var))
            || !is_register(par[2], var))
    {
        ft_putendl("\x1b[31;1mError: invalid arguments.\nExpected: lldi [T_REG | T_DIR | T_IND], [T_REG | T_DIR], [T_REG].");
        ft_putstr("Got: \"");
        ft_putstr(var->temp_input->line);
        ft_putstr("\" - line #");
        ft_putnbr(var->temp_input->line_no);
        exit(EXIT_FAILURE);
        //free  split and list and par
    }
    return (1);
}

int			check_lfork(char **args, t_main *var)
{
	 int         i;
    char        **par;

    i = 0;
    if (!args[1])
    {
        ft_putendl("\x1b[31;1mError: mnemonic was unaccompanied by arguments.\nExpected: lfork [T_DIRECT].");
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
    if (i > 1)
    {
        ft_putendl("\x1b[31;1mError: too many arguments.\nExpected: lfork [T_DIRECT].");
        ft_putstr("Got: \"");
        ft_putstr(var->temp_input->line);
        ft_putstr("\" - line #");
        ft_putnbr(var->temp_input->line_no);
        exit(EXIT_FAILURE);
        //free split and list and par;
    }
    if (!is_direct(*par, var))
    {
        ft_putendl("\x1b[31;1mError: invalid argument.\nExpected: lfork [T_DIRECT].");
        ft_putstr("Got: \"");
        ft_putstr(var->temp_input->line);
        ft_putstr("\" - line #");
        ft_putnbr(var->temp_input->line_no);
        exit(EXIT_FAILURE);
        //free  split and list and par
    }
    return (1);}
