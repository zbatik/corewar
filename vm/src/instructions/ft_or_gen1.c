/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_gen1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:25:14 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/21 23:12:06 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int do_or_op(int param1, int param2, t_opnum op)
{
	int val;

	if (op == e_or)
        val = param1 | param2;        
	else if (op == e_and)
        val = param1 & param2;
	else if (op == e_xor)
        val = param1 ^ param2;
	else
		val = 0;
	return (val);
}

static int ft_or_gen(t_core *core, t_process *cursor, t_opnum op)
{
    int param1;
    int param2;
    int val;
    int byte_count;
	int reg;

    byte_count = general_processing(core, cursor, op);
    if (byte_count == 1)
        return (byte_count);
    param1 = 0;
    param2 = 0;
    if (0 == ft_op(core, cursor, &param1, &param2))
		return (1);
	val = do_or_op(param1, param2, op);
	reg = CORE_VAL(byte_count - 1);
	modify_carry(core, cursor, val);
    cpy_int_to_reg(cursor, val, reg);
	if (core->pbp)
		ft_printf(1, na, "doing a '%s' operation on %d and %d storing result %d in r%d\n", 
		index_opinfo(op).instruction, param1, param2, val, reg);
    return (byte_count);
}

int ft_or(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_or));
}

int ft_xor(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_xor));
}

int ft_and(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_and));
}