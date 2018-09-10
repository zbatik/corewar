/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:31:24 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/10 11:34:28 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_lfork(t_core *core, t_process *cursor)
{    
    t_opnum num;
    t_opinfo info; 

    num = core->mem[cursor->pc];
    info = index_opinfo(num);
    ft_putendl(info.instruction);
    info = index_opinfo(e_lfork);
    ft_putendl(info.instruction);
    return (5);
}