/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:31:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 11:37:06 by zbatik           ###   ########.fr       */
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

    general_processing(core, cursor, e_add);
    i = -1;
    while (++i < 3)
    {
        if (!valid_reg(MEM_VAL_PC_RELATIVE(2 + i)))
            return (1);
    }
    r1_val = byte_to_int(cursor->reg[core->mem[cursor->pc + 2]], 4);
    r2_val = byte_to_int(cursor->reg[core->mem[cursor->pc + 3]], 4);
    r3 = core->mem[cursor->pc + 4];
    sum = r1_val + r2_val;
    write_to_reg(cursor, r3, sum);
    return (5);
}