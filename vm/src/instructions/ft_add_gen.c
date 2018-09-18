/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:33:33 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 12:42:33 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int ft_add_gen(t_core *core, t_process *cursor, t_opnum op)
{    
    int i;
    int r1_val;
    int r2_val;
    int r3;
    int result;

    general_processing(core, cursor, op);
    i = -1;
    while (++i < 3)
    {
        if (!valid_reg(MEM_VAL_PC_RELATIVE(2 + i)))
            return (1);
    }
    r1_val = byte_to_int(cursor->reg[MEM_VAL_PC_RELATIVE(2)], 4);
    r2_val = byte_to_int(cursor->reg[MEM_VAL_PC_RELATIVE(3)], 4);
    r3 = MEM_VAL_PC_RELATIVE(4);
	result = 0;
	if (op == e_add)
    	result = r1_val + r2_val;
	else if (op == e_sub)
		result = r1_val - r2_val;
    write_to_reg(cursor, r3, result);
    return (5);
}

int ft_add(t_core *core, t_process *cursor)
{
	return(ft_add_gen(core, cursor, e_add));
}

int ft_sub(t_core *core, t_process *cursor)
{
	return(ft_add_gen(core, cursor, e_sub));
}