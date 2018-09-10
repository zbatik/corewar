/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:31:46 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/10 16:57:06 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_add(t_core *core, t_process *cursor)
{
    t_opnum num;
    t_opinfo info; 

    num = core->mem[cursor->pc];
    info = index_opinfo(num);
    ft_putstr("received op: ");
    ft_putendl(info.instruction);
    ft_putstr("expected op: ");
    info = index_opinfo(e_add);
    ft_putendl(info.instruction);
    return (5);
}