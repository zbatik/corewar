/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_gen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:41:53 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 01:45:29 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int ft_or_type(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int success;

    if (PARA_ENCODE_BYTE == RRR)
        success = op_rrr(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == RIR)
        success = op_rir(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == RDR)
        success = op_rdr(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == DIR)
        success = op_dir(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == DRR)
        success = op_drr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == DDR)
        success = op_ddr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IDR)
        success = op_idr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IRR)
        success = op_irr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IIR)
        success = op_iir(core, cursor, param1, param2);
    else
    {
        corrupted_encoding_byte();
        success = 0;
    }
    return (success);
}

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

int ft_or_gen(t_core *core, t_process *cursor, t_opnum op)
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
    if (0 == ft_or_type(core, cursor, &param1, &param2))
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