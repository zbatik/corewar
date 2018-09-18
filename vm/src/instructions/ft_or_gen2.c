/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_gen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:41:53 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 16:02:36 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int op_rrr(t_core *core, t_process *cursor, int *param1, int *param2)
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

static int op_rir(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int i;
    int ret;

    i = -1;
    while (++i < 3)
    ret = valid_reg(core->mem[cursor->pc + 2]);
    ret = ret && valid_reg(core->mem[cursor->pc + 5]);
    if (!ret)
        return (1);
    *param1 = byte_to_int(cursor->reg[cursor->pc + 2], 4);
    *param2 = byte_to_int(core->mem + cursor->pc + 3, 4);
    return (6);
}

static int op_dir(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int i;
    
    if (!valid_reg(core->mem[cursor->pc + 5]))
        return (1);
    i = -1;
    *param1 = byte_to_int(cursor->reg[cursor->pc + 2], 4);
    *param2 = byte_to_int(core->mem + cursor->pc + 6, 2);
    return (9);
}

static int op_drr(t_core *core, t_process *cursor, int *param1, int *param2)
{
        int i;

    i = -1;
    while (++i < 2)
    {
        if (!valid_reg(core->mem[cursor->pc + 2 + i]))
            return (1);
    }
    *param1 = byte_to_int(core->mem + cursor->pc + 2, 4);
    *param2 = byte_to_int(cursor->reg[cursor->pc + 6], 4);
    return (8);
}

int ft_op(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int jump;

    jump = 1;
    if (PARA_ENCODE_BYTE == RRR)
        jump =  op_rrr(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == RIR)
        jump = op_rir(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == DIR)
        jump = op_dir(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == DRR)
        jump = op_drr(core, cursor, param1, param2);
    return (jump);
}