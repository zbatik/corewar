/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:14 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/23 17:26:22 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int sti_rrr(t_core *core, t_process *cursor)
{
    int input1;
    int input2;
    int reg1;
    int reg2;
    int reg3;

    reg1 = CORE_VAL(2);
    reg2 = CORE_VAL(3);
    reg3 = CORE_VAL(4);
    if (0 == convert_reg_to_int(cursor, reg1, &input1))
        return (0);
    if (0 ==  convert_reg_to_int(cursor, reg2, &input2))
        return (0);
    if (0 == cpy_int_to_reg(cursor, input1 + input2, reg3))
        return (0);
    if (PBP)
        ft_printf(1, na, "endcoding %x: copy %d at r%d + %d at r%d to r%d\n",
        PARA_ENCODE_BYTE, input1, reg1, input2, reg2, reg3);
    return (1); 
}

static int sti_rdr_rir(t_core *core, t_process *cursor)
{
    int input1;
    int input2;
    int param2;
    int reg1;
    int reg2;

    reg1 = CORE_VAL(2);
    reg2 = CORE_VAL(5);
    if (0 == convert_reg_to_int(cursor, reg1, &input1))
        return (0);
    param2 = convert_bytes_to_int(core, PC(3), 2);
    if (PARA_ENCODE_BYTE == RIR)
        input2 = convert_bytes_to_int(core, PC(param2), 4);
    else if (PARA_ENCODE_BYTE == RDR)
        input2 = param2;
    else
        return (0);
    if (0 == cpy_int_to_reg(cursor, input1 + input2, reg2))
        return (0);
    if (PBP)
        ft_printf(1, na, "endcoding %x: copy %d at r%d + %d to r%d\n",
        PARA_ENCODE_BYTE, input1, reg1, input2, reg2);
    return (1);
}

static int sti_rid_rdd(t_core *core, t_process *cursor)
{
    int input1;
    int input2;
    int param2;
    int input;
    int cpy_location;

    if (0 == convert_reg_to_int(cursor, CORE_VAL(2), &input1))
        return (0);
    param2 = convert_bytes_to_int(core, PC(3), 2);
    if (PARA_ENCODE_BYTE == RID)
        input2 = convert_bytes_to_int(core, PC(param2), 4);
    else if (PARA_ENCODE_BYTE == RDD)
        input2 = param2;
    else
        return (0);
    cpy_location = convert_bytes_to_int(core, PC(5), 2);
    input = rev_endian(input1 + input2);
    cpy_straight_to_mem(core, cursor, (t_byte*)&input, cpy_location);
    if (PBP)
        ft_printf(1, na, "endcoding %x: copy %d at r%d + %d to %d\n",
        PARA_ENCODE_BYTE, input1, CORE_VAL(2), input2, cpy_location);
    return (1);
}

static int sti_rrd(t_core *core, t_process *cursor)
{
    int input1;
    int input2;
    int input;
    int cpy_location;

    if (0 == convert_reg_to_int(cursor, CORE_VAL(2), &input1))
        return (0);
    if (0 == convert_reg_to_int(cursor, CORE_VAL(3), &input2))
        return (0);
    cpy_location = convert_bytes_to_int(core, PC(4), 2);
    input = rev_endian(input1 + input2);
    cpy_straight_to_mem(core, cursor, (t_byte*)&input, cpy_location);
    if (PBP)
        ft_printf(1, na, "endcoding %x: copy %d at r%d + %d at r%d to %d\n",
        PARA_ENCODE_BYTE, input1, CORE_VAL(2), input2, CORE_VAL(3), cpy_location);
    return (1);
}

int ft_sti(t_core *core, t_process *cursor)
{
    int byte_count;
    int success;

    byte_count = general_processing(core, cursor, e_sti);
	if (PARA_ENCODE_BYTE == RRR)
		success = sti_rrr(core, cursor);
	else if (PARA_ENCODE_BYTE == RDR || PARA_ENCODE_BYTE  == RIR)
		success = sti_rdr_rir(core, cursor);
	else if (PARA_ENCODE_BYTE  == RRD)
		success = sti_rrd(core, cursor);
	else if (PARA_ENCODE_BYTE == RDD || PARA_ENCODE_BYTE  == RID)
		success = sti_rid_rdd(core, cursor);
    else
        return(corrupted_encoding_byte(core));
    if (success == 0)
        return (1);
    return (byte_count);
}