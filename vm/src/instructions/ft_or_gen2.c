/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_gen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:41:53 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:26:24 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	ft_or_type(t_core *core, t_process *cursor, int *para1, int *para2)
{
	if (PARA_ENCODE_BYTE == RRR)
		return (op_rrr(core, cursor, para1, para2));
	else if (PARA_ENCODE_BYTE == RIR)
		return (op_rir(core, cursor, para1, para2));
	else if (PARA_ENCODE_BYTE == RDR)
		return (op_rdr(core, cursor, para1, para2));
	else if (PARA_ENCODE_BYTE == DIR)
		return (op_dir(core, cursor, para1, para2));
	else if (PARA_ENCODE_BYTE == DRR)
		return (op_drr(core, cursor, para1, para2));
	else if (PARA_ENCODE_BYTE == DDR)
		return (op_ddr(core, cursor, para1, para2));
	else if (PARA_ENCODE_BYTE == IDR)
		return (op_idr(core, cursor, para1, para2));
	else if (PARA_ENCODE_BYTE == IRR)
		return (op_irr(core, cursor, para1, para2));
	else if (PARA_ENCODE_BYTE == IIR)
		return (op_iir(core, cursor, para1, para2));
	corrupted_encoding_byte(core);
	return (0);
}

static int	do_or_op(int param1, int param2, t_opnum op)
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

int			ft_or_gen(t_core *core, t_process *cursor, t_opnum op)
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
	if (0 == cpy_int_to_reg(cursor, val, reg))
		return (1);
	if (PBP)
		ft_printf(1, na,
		"doing a '%s' operation on %d and %d storing result %d in r%d\n",
		index_opinfo(op).instruction, param1, param2, val, reg);
	return (byte_count);
}
