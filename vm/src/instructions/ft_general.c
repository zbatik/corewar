/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:21:05 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/19 14:25:22 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static void    modify_carry(t_process *cursor, t_opnum op)
{
    if ((index_opinfo(op)).modifies_carry)
    {   
        ft_putendl_cl("carry modified", y);
        cursor->carry = !cursor->carry;
    }
}

int            general_processing(t_core *core, t_process *cursor, t_opnum op)
{
    int byte_count;

    if (core->pbp)
        print_instr_info(core, cursor, op);
    byte_count = byte_counter(core, cursor->pc, op);
    if (core->pbp && byte_count == 1)
        ft_putendl("corrupted encoding byte");
    modify_carry(cursor, op);
    return (byte_count);
}