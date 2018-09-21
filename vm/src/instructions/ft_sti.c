/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:14 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/21 15:11:47 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
static void sti_rrr(t_core *core, t_process *cursor, int *para2, int *para3)
{
    int r2;
    int r3;

    r2 = MEM_VAL_PC_RELATIVE(3);
    r3 = MEM_VAL_PC_RELATIVE(4);
    convert_reg_to_int(cursor, r2, para2);
    convert_reg_to_int(cursor, r3, para3);
}

static void sti_rdr_rir(t_core *core, t_process *cursor, int *para2, int *para3)
{
    int r3;

    *para2 = convert_2b_to_int(core, 3);
    r3 = MEM_VAL_PC_RELATIVE(5);
    convert_reg_to_int(cursor, r3, para3);
}

static void sti_rid_rdd(t_core *core, int *para2, int *para3)
{
    *para2 = convert_2b_to_int(core, 3);
    *para3 = convert_2b_to_int(core, 5);
}

static void sti_rrd(t_core *core, t_process *cursor, int *para2, int *para3)
{
    int r2;

    *para2 = convert_2b_to_int(core, 3);
    r2 = MEM_VAL_PC_RELATIVE(3);
    convert_reg_to_int(cursor, r2, );
    if (!valid_reg(r2))
        *para3 = 0;
    else
        *para3 = convert_reg_to_int(cursor->reg[r2]);
}
*/
int ft_sti(t_core *core, t_process *cursor)
{
   int byte_count;
    /*int cpy_to;
    int para2;
    int para3;
    int copy;

    para2 = 0;
    para3 = 0;*/
    byte_count = general_processing(core, cursor, e_sti);
    /*if (!convert_reg_to_int(cursor, MEM_VAL_PC_RELATIVE(2), &cpy_to))
        return (1);
	if (PARA_ENCODE_BYTE == RRR)
		sti_rrr(core, cursor, &para2, &para3);
	else if (PARA_ENCODE_BYTE  == RDR || PARA_ENCODE_BYTE  == RIR)
		sti_rdr_rir(core, cursor, &para2, &para3);
	else if (PARA_ENCODE_BYTE  == RRD)
		sti_rrd(core, cursor, &para2, &para3);
	else if (PARA_ENCODE_BYTE == RDD || PARA_ENCODE_BYTE  == RID)
		sti_rid_rdd(core, &para2, &para3);
    else
        corrupted_encoding_byte();
    rev_endian(para2 + para3);
    copy = rev_endian(para2 + para3);
    cpy_straight_to_mem(core, (t_byte*)&copy, cpy_to);*/
    return (byte_count);
}