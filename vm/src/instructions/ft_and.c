/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:00:43 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/13 18:14:31 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int op_rrr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int i;

    i = -1;
    while (++i < 3)
    {
        if (!valid_reg(core->mem[cursor->pc + 2 + i]))
            return (1);
    }
    *param1 = byte_to_int(cursor->reg[cursor->pc + 2], 4);
    *param2 = byte_to_int(cursor->reg[cursor->pc + 3], 4);
    return (5);
}

int op_rir(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int i;
    int ret;

    i = -1;
    while (++i < 3)
    ret = valid_reg(core->mem[cursor->pc + 2]))
    ret = ret | valid_reg(core->mem[cursor->pc + 5])
    if (!ret)
        return (1);
    *param1 = byte_to_int(cursor->reg[cursor->pc + 2], 4);
    *param2 = byte_to_int(cursor->reg[cursor->pc + 3], 4);
    return (6);
}

int op_dir(t_core *core, t_process *cursor, int *param1, int *param2)
{
        int i;

    i = -1;
    while (++i < 3)
    {
        if (!valid_reg(core->mem[cursor->pc + 2 + i]))
            return (1);
    }
    *param1 = byte_to_int(cursor->reg[cursor->pc + 2], 4);
    *param2 = byte_to_int(cursor->reg[cursor->pc + 3], 4);
    return (9);
}

int op_drr(t_core *core, t_process *cursor, int *param1, int *param2)
{
        int i;

    i = -1;
    while (++i < 3)
    {
        if (!valid_reg(core->mem[cursor->pc + 2 + i]))
            return (1);
    }
    *param1 = byte_to_int(cursor->reg[cursor->pc + 2], 4);
    *param2 = byte_to_int(cursor->reg[cursor->pc + 3], 4);
    return (8);
}

int ft_and(t_core *core, t_process *cursor)
{
    int param1;
    int param2;
    int r3;
    int jump;
    if (DEBUG)
        print_instr_info(core, e_and, cursor->pc);
    if (core->mem[cursor->pc] == RRR)
        jump =  op_rrr(core, cursor, &param1, &param2);
    else if (core->mem[cursor->pc] == RIR)
        jump = op_rir(core, cursor, &param1, &param2);
    else if (core->mem[cursor->pc] == DIR)
        jump = op_dir(core, cursor, &param1, &param2);
    else if (core->mem[cursor->pc] == DRR)
        jump = op_drr(core, cursor, &param1, &param2;
    else
        return (corrupted_encoding_byte());
    if (jump == 1)
        return (jump);
    write_to_reg(cursor, r3, param1 & param2);

    return (jump);
}