/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:34:11 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 10:28:02 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_or(t_core *core, t_process *cursor)
{
    int param1;
    int param2;
    int r3;
    int jump;

    general_processing(core, cursor, e_or);
    param1 = 0;
    param2 = 0;
    jump = ft_op(core, cursor, &param1, &param2);
    if (jump == 1)
        return (jump);
    r3 = core->mem[cursor->pc + jump - 1];
    write_to_reg(cursor, r3, param1 | param2);
    return (jump);
}