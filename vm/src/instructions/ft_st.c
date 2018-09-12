/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:59:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/12 15:27:01 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_st(t_core *core, t_process *cursor)
{
    int r1;
    int r2;

    if (DEBUG)
        print_instr_info(core, e_st, cursor->pc);
    r1 = core->mem[cursor->pc + 2];
    if (!valid_reg(r1))
        return (1);
    if (RR == core->mem[cursor->pc + 1])
    {
        r2 = core->mem[cursor->pc + 3];
        ft_strncpy((char*)cursor->reg[2], (char*)cursor->reg[1], 4);
        if (!valid_reg(r2))
            return (1);
        return (4);
    }
    else if (RI == core->mem[cursor->pc + 1])
    {
        cpy_from_reg(core, cursor->reg[r1], 
            cursor->pc + byte_to_int((unsigned char*)core->mem, 2));
        return (5);
    }
    else
    {
        ft_putendl("corrupted uncoding byte"); 
        return (1);
    }
    return (5);
}