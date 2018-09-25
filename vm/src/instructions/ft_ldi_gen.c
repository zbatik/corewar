/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:46:56 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:14:26 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	ldi_rrr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int reg1;
	int reg2;

	reg1 = CORE_VAL(2);
	reg2 = CORE_VAL(3);
	if (0 == convert_reg_to_int(cursor, reg1, param1))
		return (0);
	if (0 == convert_reg_to_int(cursor, reg2, param2))
		return (0);
	if (PBP)
		ft_printf(1, na, "RRR: %x recieved r%d and r%d\n", RRR, reg1, reg2);
	return (1);
}

static int	ldi_type(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int success;

	if (PARA_ENCODE_BYTE == RDR)
		success = ldi_rdr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == RRR)
		success = ldi_rrr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == DDR)
		success = ldi_ddr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == DRR)
		success = ldi_drr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IDR)
		success = ldi_idr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IRR)
		success = ldi_irr(core, cursor, param1, param2);
	else
		return (0);
	return (success);
}

static int	ft_ldi_gen(t_core *core, t_process *cursor, t_opnum op)
{
	int byte_count;
	int param1;
	int param2;
	int val;
	int reg;

	byte_count = general_processing(core, cursor, op);
	if (byte_count == 1)
		return (byte_count);
	if (0 == ldi_type(core, cursor, &param1, &param2))
		return (1);
	if (op == e_lldi)
		val = param1 + param2;
	else
		val = (param1 + param2) % IDX_MOD;
	reg = CORE_VAL(byte_count - 1);
	cpy_int_to_reg(cursor, val, reg);
	modify_carry(core, cursor, val);
	if (PBP)
		ft_printf(1, na, "storing %d (%d + %d) in r%d\n",
		val, param1, param2, reg);
	return (byte_count);
}

int			ft_ldi(t_core *core, t_process *cursor)
{
	return (ft_ldi_gen(core, cursor, e_ldi));
}

int			ft_lldi(t_core *core, t_process *cursor)
{
	return (ft_ldi_gen(core, cursor, e_lldi));
}
