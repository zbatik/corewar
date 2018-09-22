/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:14 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 07:30:07 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int sti_rrr(t_core *core, t_process *cursor)
{
    int input1;
    int input2;
    int ret1;
    int ret2;

    ret1 = convert_reg_to_int(cursor, CORE_VAL(3), &input1);
    ret2 = convert_reg_to_int(cursor, CORE_VAL(4), &input2);
    if ((ret1 == 0) || (ret2 == 0))
        return (0);
    if (0 == cpy_int_to_reg(cursor, input1 + input2, CORE_VAL(5)))
        return (0);
    return (1);
}

static int sti_rdr_rir(t_core *core, t_process *cursor)
{
    int input1;
    int input2;
    int param2;

    if (0 == convert_reg_to_int(cursor, CORE_VAL(3), &input1))
        return (0);
    param2 = convert_bytes_to_int(core, PC(4), 2);
    if (PARA_ENCODE_BYTE == RIR)
        input2 = convert_bytes_to_int(core, PC(param2), 4);
    else if (PARA_ENCODE_BYTE == RDR)
        input2 = param2;
    else
        return (0);
    if (0 == cpy_int_to_reg(cursor, input1 + input2, CORE_VAL(5)))
        return (0);
    return (1);
}

static int sti_rid_rdd(t_core *core, t_process *cursor)
{
    int input1;
    int input2;
    int param2;
    int input;
    int cpy_location;

    if (0 == convert_reg_to_int(cursor, CORE_VAL(3), &input1))
        return (0);
    param2 = convert_bytes_to_int(core, PC(4), 2);
    if (PARA_ENCODE_BYTE == RIR)
        input2 = convert_bytes_to_int(core, PC(param2), 4);
    else if (PARA_ENCODE_BYTE == RDR)
        input2 = param2;
    else
        return (0);
    cpy_location = convert_bytes_to_int(core, PC(6), 2);
    input = input1 + input2;
    cpy_straight_to_mem(core, (t_byte*)&input, cpy_location);
    return (1);
}

static int sti_rrd(t_core *core, t_process *cursor)
{
    int input1;
    int input2;
    int input;
    int cpy_location;

    if (0 == convert_reg_to_int(cursor, CORE_VAL(3), &input1))
        return (0);
    if (0 == convert_reg_to_int(cursor, CORE_VAL(4), &input2))
        return (0);
    cpy_location = convert_bytes_to_int(core, PC(5), 2);
    input = input1 + input2;
    cpy_straight_to_mem(core, (t_byte*)&input, cpy_location);
    return (1);
}

int ft_sti(t_core *core, t_process *cursor)
{
    int byte_count;
    int ret;

    byte_count = general_processing(core, cursor, e_sti);
	if (PARA_ENCODE_BYTE == RRR)
		ret = sti_rrr(core, cursor);
	else if (PARA_ENCODE_BYTE == RDR || PARA_ENCODE_BYTE  == RIR)
		ret = sti_rdr_rir(core, cursor);
	else if (PARA_ENCODE_BYTE  == RRD)
		ret = sti_rrd(core, cursor);
	else if (PARA_ENCODE_BYTE == RDD || PARA_ENCODE_BYTE  == RID)
		ret = sti_rid_rdd(core, cursor);
    else
        return(corrupted_encoding_byte());
    if (ret == 0)
        return (1);
    return (byte_count);
}