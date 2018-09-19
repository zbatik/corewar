/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:33:33 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 15:59:17 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int do_add_op(int r1_val, int r2_val, t_opnum op)
{
    int result;

	if (op == e_add)
    	result = r1_val + r2_val;
	else if (op == e_sub)
		result = r1_val - r2_val;
    else
        result = 0;
    return (result);
}   

static int ft_add_gen(t_core *core, t_process *cursor, t_opnum op)
{    
    int i;
    int r1_val;
    int r2_val;
    int r3;
    int byte_count;

    byte_count = general_processing(core, cursor, op);
    i = -1;
    while (++i < 3)
    {
        if (!valid_reg(MEM_VAL_PC_RELATIVE(2 + i)))
            return (1);
    }
    r1_val = byte_to_int(cursor->reg[MEM_VAL_PC_RELATIVE(2)], 4);
    r2_val = byte_to_int(cursor->reg[MEM_VAL_PC_RELATIVE(3)], 4);
    r3 = MEM_VAL_PC_RELATIVE(4);
    write_to_reg(cursor, r3, do_add_op(r1_val, r2_val, op));
    return (byte_count);
}

int ft_add(t_core *core, t_process *cursor)
{
	return(ft_add_gen(core, cursor, e_add));
}

int ft_sub(t_core *core, t_process *cursor)
{
	return(ft_add_gen(core, cursor, e_sub));
}