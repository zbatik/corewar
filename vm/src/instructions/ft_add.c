/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:31:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/12 15:55:19 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_add(t_core *core, t_process *cursor)
{    
    int i;
    int r1_val;
    int r2_val;
    int r3;
    int sum;

    if (DEBUG)
        print_instr_info(core, e_add, cursor->pc);
    i = -1;
    while (++i < 3)
    {
        if (!valid_reg(core->mem[cursor->pc + 2 + i]))
            return (1);
    }
    r1_val = byte_to_int(cursor->reg[core->mem[cursor->pc + 2]], 4);
    r2_val = byte_to_int(cursor->reg[core->mem[cursor->pc + 3]], 4);
    r3 = core->mem[cursor->pc + 4];
    sum = r1_val + r2_val;
    ft_strncpy((char*)cursor->reg[r3], (char*)&sum, 4);
    return (5);
}