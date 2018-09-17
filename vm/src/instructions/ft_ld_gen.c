/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:58:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 14:22:25 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	applies to both ld and lld
*/

static int ft_ld_gen(t_core *core, t_process *cursor, t_opnum op)
{
    int rX;
    int param_add_byte;
    int ld_ind;
	int ld_val;

    general_processing(core, cursor, op);
    if (DR == PARA_ENCODE_BYTE)
        param_add_byte = 2;
    else if (IR == PARA_ENCODE_BYTE)
        param_add_byte = 0;
    else
        return (corrupted_encoding_byte());
	ld_ind = byte_to_int(MEM_PNT_PC_RELATIVE(2), 2 + param_add_byte);
	if (op == e_ld)
		ld_val = MEM_VAL_PC_REL_MOD(ld_ind);
	if (op == e_lld)
		ld_val = MEM_VAL_PC_RELATIVE(ld_ind);
    rX = MEM_VAL_PC_RELATIVE(4 + param_add_byte);
    if (!valid_reg(rX))
        return (1);
    write_to_reg(cursor, rX, ld_val);
    return (5 + param_add_byte);
}

int ft_ld(t_core *core, t_process *cursor)
{
	return(ft_ld_gen(core, cursor, e_ld));
}

int ft_lld(t_core *core, t_process *cursor)
{
	return(ft_ld_gen(core, cursor, e_ld));
}
