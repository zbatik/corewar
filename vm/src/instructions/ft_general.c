/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:21:05 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/23 16:05:18 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void    modify_carry(t_core *core, t_process *cursor, int val)
{
    if (val == 0)
    {   
        if (PBP && cursor->carry == 1)
            ft_putendl_cl("carry unchanged at 1", y);
        else if (PBP && cursor->carry == 0)
            ft_putendl_cl("carry flipped from 0 to 1", y);
        cursor->carry = 1;
    }
    else
    {
        if (PBP && cursor->carry == 0)
            ft_putendl_cl("carry unchanged at 0", y);
        else if (PBP && cursor->carry == 1)
            ft_putendl_cl("carry flipped from 1 to 0", y);
        cursor->carry = 0;
    }
}

int            general_processing(t_core *core, t_process *cursor, t_opnum op)
{
    int byte_count;

    if (PBP)
        print_instr_info(core, cursor, op);
    byte_count = byte_counter(core, cursor->pc, op);
    if (PBP && byte_count == 1)
        corrupted_encoding_byte(core);
    return (byte_count);
}