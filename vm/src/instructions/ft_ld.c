/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:59:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/12 13:36:50 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_ld(t_core *core, t_process *cursor)
{
    int rX;
    int param_add_byte;
    if (DEBUG)
        print_instr_info(core, e_ld, cursor->pc);
    if (DR == core->mem[cursor->pc + 1])
        param_add_byte = 2;
    else if (IR == core->mem[cursor->pc + 1])
        param_add_byte = 0;
    else
    {
        ft_putendl("corrupted uncoding byte"); 
        return (1);
    }
    rX = core->mem[cursor->pc + 4 + param_add_byte];
    if (!valid_reg(rX))
        return (1);
    cursor->carry = !cursor->carry;
    // do copy
    return (5 + param_add_byte);
}