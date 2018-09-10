/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:59:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/10 18:21:34 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_ld(t_core *core, t_process *cursor)
{
    t_opnum num;
    t_opinfo info;
    int rX;
    

    if (DR == core->mem[cursor->pc + 1])
    {
        rX = core->mem[cursor->pc + 6];
        if (!valid_reg(rX))
            return (1);
        return (7)
    }
    else if (IR == core->mem[cursor->pc + 1])
    {
        rX = core->mem[cursor->pc + 4];
        if (!valid_reg(rX))
            return (1);
        return (5)
    }
    else
    {
        //corrupted uncoding byte
        return (1);
    }
    num = core->mem[cursor->pc];
    info = index_opinfo(num);
    ft_putendl(info.instruction);
    info = index_opinfo(e_ld);
    ft_putendl(info.instruction);
    return (5);
}