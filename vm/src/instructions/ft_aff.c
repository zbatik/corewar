/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:32:26 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/12 16:06:40 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_aff(t_core *core, t_process *cursor)
{
    int r1;
    if (DEBUG)
        print_instr_info(core, e_aff, cursor->pc);
    r1 = core->mem[cursor->pc + 2];
    if (core->mem[cursor->pc + 1] == 0x40)
    {
        ft_putendl("corrupted encoding byte");
        return (1);
    }
    if (!valid_reg)
        return (1);
    ft_putchar((char)cursor->reg[r1][REG_SIZE - 1]);
    return (3);
}