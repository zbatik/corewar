/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:33:33 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 05:34:38 by zbatik           ###   ########.fr       */
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
    int r1_val;
    int r2_val;
    int val;
    int byte_count;

    r1_val = 0;
    r2_val = 0;
    byte_count = general_processing(core, cursor, op);
    if (!convert_reg_to_int(cursor, CORE_VAL(2), &r1_val))
        return (1);
    if (!convert_reg_to_int(cursor, CORE_VAL(3), &r2_val))
        return (1);
    val = do_add_op(r1_val, r2_val, op);
    if (PBP)
        ft_printf(1, na, "%s %d from r%d to %d from r%d and store in r%d\n", 
            index_opinfo(op).instruction, 
                r1_val, CORE_VAL(2), r2_val, CORE_VAL(3), CORE_VAL(4));
    modify_carry(core, cursor, val);
    cpy_int_to_reg(cursor, val, CORE_VAL(4));
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