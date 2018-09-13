/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fork_and_lld.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:33:52 by emaune            #+#    #+#             */
/*   Updated: 2018/09/13 15:04:28 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			check_fork(char **args, t_main *var)
{
	int         i;
    char        **par;

    i = 0;
    if (!args[1])
    {
        ft_putendl("\x1b[31;1mError: mnemonic was unaccompanied by arguments.\nExpected: fork [T_DIRECT].");
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
        ft_putendl("\x1b[31;1mError: too many arguments.\nExpected: fork [T_DIRECT].");
        ft_putstr("Got: \"");
        ft_putstr(var->temp_input->line);
        ft_putstr("\" - line #");
        ft_putnbr(var->temp_input->line_no);
        exit(EXIT_FAILURE);
        //free split and list and par;
    }
    if (!is_direct(*par, var))
    {
        ft_putendl("\x1b[31;1mError: invalid argument.\nExpected: fork [T_DIRECT].");
        ft_putstr("Got: \"");
        ft_putstr(var->temp_input->line);
        ft_putstr("\" - line #");
        ft_putnbr(var->temp_input->line_no);
        exit(EXIT_FAILURE);
        //free  split and list and par
    }
    return (1);
}

int			check_lld(char **args, t_main *var)
{
	int         i;
    char        **par;

    i = 0;
    if (!args[1])
    {
        ft_putendl("\x1b[31;1mError: mnemonic was unaccompanied by arguments.\nExpected: lld [T_DIRECT | T_IND], [T_REG].");
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
