/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:59:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 04:10:37 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int st_rr(t_core *core, t_process *cursor, int src_reg)
{
    int dst_reg;

    dst_reg = CORE_VAL(3);
    if (0 == cpy_reg_to_reg(cursor, dst_reg, src_reg))
        return (0);
    if (PBP)
        ft_printf(1, na, "RR %x: r%d copied to r%d\n", RR, src_reg, dst_reg);
    return (1);
}

static int st_ri(t_core *core, t_process *cursor, int src_reg)
{
    int ind;
    int indir;
    int read_from;

    indir = PC(3);
    read_from = PC(convert_bytes_to_int(core, indir, 2) % IDX_MOD);
    ind = convert_bytes_to_int(core, read_from, 4);
	if (0 == cpy_reg_to_mem(core, cursor, src_reg, ind))
        return (0);
    if (PBP)
		ft_printf(1, na, "RI: %x r%d copied to index %d\n", RI, src_reg, ind);
    return (1);
}

int ft_st(t_core *core, t_process *cursor)
{
    int src_reg;
    int ret;
    int byte_count;

    byte_count = general_processing(core, cursor, e_st);
    src_reg = CORE_VAL(2);
    if (RR == PARA_ENCODE_BYTE)
        ret = st_rr(core, cursor, src_reg);
    else if (RI == PARA_ENCODE_BYTE)
    	ret = st_ri(core, cursor, src_reg);
    else
        return (corrupted_encoding_byte());
	if (ret == 0)
		return (1);
    return (byte_count);
}