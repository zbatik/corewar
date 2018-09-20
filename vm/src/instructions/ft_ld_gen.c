/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:58:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/20 18:31:51 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	applies to both ld and lld
*/

static int ft_ld_gen(t_core *core, t_process *cursor, t_opnum op)
{
    int reg;
    int param_add_byte;
    int start_ind;
    int byte_count;

    byte_count = general_processing(core, cursor, op);
    if (byte_count == 1)
        return (byte_count);
    param_add_byte = 0;
    if (DR == PARA_ENCODE_BYTE)
        param_add_byte = 2;
    else if (IR == PARA_ENCODE_BYTE)
        param_add_byte = 0;
    reg = MEM_VAL_PC_RELATIVE(4 + param_add_byte);
	start_ind = convert_bytes_to_int(core, 2, 2 + param_add_byte);
	if (op == e_ld)
		start_ind = start_ind % IDX_MOD;
    cpy_mem_to_reg(core, cursor, reg, start_ind);
    return (byte_count);
}

int ft_ld(t_core *core, t_process *cursor)
{
	return(ft_ld_gen(core, cursor, e_ld));
}

int ft_lld(t_core *core, t_process *cursor)
{
	return(ft_ld_gen(core, cursor, e_ld));
}
