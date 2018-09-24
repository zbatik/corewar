/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:46:56 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/23 17:07:20 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int ldi_type(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int success;

	if (PARA_ENCODE_BYTE == RDR)
		success = ld_rdr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == RRR)
		success = op_rrr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == DDR)
		success = ld_ddr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == DRR)
		success = ld_drr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IDR)
		success = ld_idr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IRR)
		success = op_irr(core, cursor, param1, param2);
	else
		return(0);
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
	val = param1 + param2;
	reg = CORE_VAL(byte_count - 1);
	cpy_int_to_reg(cursor, val, reg);
	if (PBP)
		ft_printf(1, na, "storing %d (%d + %d) in r%d\n", val, param1, param2, reg);
	return (byte_count);
}

int ft_ldi(t_core *core, t_process *cursor)
{
	return(ft_ldi_gen(core, cursor, e_ldi));
}

int ft_lldi(t_core *core, t_process *cursor)
{
	return(ft_ldi_gen(core, cursor, e_lldi));
}