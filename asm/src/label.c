/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:26:08 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/05 18:25:46 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

int instruction_arg_size(t_opnum op, const char *instruction_line)
{
    char    **split;
    int     num_args;
    char    *tmp;
    int     i;

    i = 0;
    tmp = (char *)instruction_line;
    tmp += ft_indexcin(instruction_line, ' ');
    split = ft_strsplit(tmp, ',');
    if (split == NULL)
        printf("theres only one arg\n");
    num_args = (index_opinfo(op)).num_args;
    printf("%d: num_args, split[0]: %s", num_args, split[0]);
    while(split != NULL && i < num_args)
    {
        if (split[i][0] == '%')
            ft_putendl("indeirect");
        else
            ft_putendl("direct");
        i++;
    }
    return (i);
}

int instruction_byte_size(char *instruction_line)
{
    t_opnum op;
    int     byte_size;
    short   i;

    byte_size = 0;
    op = inst_to_enum((char*)instruction_line);
    i = -1;
    while (++i < (index_opinfo(op)).num_args)
    {
        ft_putnbr(i);
    }
    if (DEBUG)
    {
        ft_putstr("Calculating byte lenght of: ");
        ft_putendl((char*)instruction_line);
        ft_putstr("Recognised as: ");
        ft_putendl((index_opinfo(op)).instruction);
        if (ft_strcmp((index_opinfo(op)).instruction, "") == 0)
        {
            ft_putendl("not an instruction");
        }
        ft_putstr("Calculate byte size of: ");
        byte_size = instruction_arg_size(op, instruction_line);
        ft_putnbr(byte_size);
        ft_putstr("\nthis instruction takes: ");
        ft_putnbr(index_opinfo(op).num_args);
        ft_putstr(" arguments");
        ft_putchar('\n');
    }
    return (byte_size);
}