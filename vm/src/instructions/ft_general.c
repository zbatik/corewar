/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:21:05 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 14:44:47 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void    modify_carry(t_process *cursor, t_opnum op)
{
    if ((index_opinfo(op)).modifies_carry)
        cursor->carry = !cursor->carry;
}

int            general_processing(t_core *core, t_process *cursor, t_opnum op)
{
    int byte_count;

    if (core->pbp)
        print_instr_info(core, op, cursor->pc);
    byte_count(core, cursor, op);
    modify_carry(cursor, op);
}

/*
int check_encoding_byte(t_byte en, t_opnum op);
{
    if (op == e_st)
    {
        if (!(en == RR || en == RI))
    }

}

void general_processing(t_core *core, t_process *cursor, t_opnum op)
{
//    int has_encoding_byte;
//    int valid;

    print_instr_info(core, op, cursor->pc);
//    has_encoding_byte = index_opinfo(op).arg_encoding_byte;
//    if (has_encoding_byte)
//        valid = check_encoding_byte(MEM_VAL_PC_RELATIVE(1), op);
//    if (!valid)
//        return (0);
    modify_carry(cursor, op);
//    return (1);
}
*/