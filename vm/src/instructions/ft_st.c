/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:59:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/20 17:45:46 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"


int ft_st(t_core *core, t_process *cursor)
{
    int src;
    int dst;
    int start_ind;
    int byte_count;
    int indir;

    byte_count = general_processing(core, cursor, e_st);
    src = MEM_VAL_PC_RELATIVE(2);
    if (RR == PARA_ENCODE_BYTE)
    {
        dst = MEM_VAL_PC_RELATIVE(3);
        ft_printf(1, na, "RR, src %d, dst %d\n", src, dst);
        if (0 == cpy_reg_to_reg(cursor, dst, src))
            return (1);
    }
    else if (RI == PARA_ENCODE_BYTE)
    {
        // problems !
        indir = convert_2b_to_int(core, MEM_VAL_PC_RELATIVE(3));
        start_ind = cursor->pc + indir;
        ft_printf(1, na, "RR, src %d, start_ind %d, indir %d\n", src, start_ind, indir);
        if (0 == cpy_reg_to_mem(core, cursor, src, start_ind))
            return (1);
    }
    else
        return (corrupted_encoding_byte());
    return (byte_count);
}