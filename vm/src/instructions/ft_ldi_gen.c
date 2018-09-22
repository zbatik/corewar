/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:46:56 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 02:15:59 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	ft_ldi_gen(t_core *core, t_process *cursor, t_opnum op)
{
	int byte_count;
	int param1;
	int param2;

	byte_count = general_processing(core, cursor, op);
	if (byte_count == 1)
        return (byte_count);
	if (PARA_ENCODE_BYTE == RDR)
		op_rdr(core, cursor, &param1, &param2);
	else if (PARA_ENCODE_BYTE == RRR)
		op_rrr(core, cursor, &param1, &param2);
	else if (PARA_ENCODE_BYTE == DDR)
		op_ddr(core, cursor, &param1, &param2);
	else if (PARA_ENCODE_BYTE == DRR)
		op_drr(core, cursor, &param1, &param2);
	else if (PARA_ENCODE_BYTE == IDR)
		op_idr(core, cursor, &param1, &param2);
	else if (PARA_ENCODE_BYTE == IRR)
		op_irr(core, cursor, &param1, &param2);
	else
		return(corrupted_encoding_byte());
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