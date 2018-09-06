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

t_arg_type parse_instruction_arg(t_byte *instruction_line);

int instruction_arg_size(t_opnum instruction, t_arg_type arg1);

int instruction_byte_size(t_byte *instruction_line)
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
        ft_putstr("Calculate byte size of: ");
        ft_putnbr(byte_size);
        ft_putchar('\n');
    }
    return (byte_size);
}