/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_gen1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:25:14 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 14:31:09 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int ft_or_gen(t_core *core, t_process *cursor, t_opnum op)
{
    int param1;
    int param2;
    int r3;
    int jump;

    general_processing(core, cursor, op);
    param1 = 0;
    param2 = 0;
    jump = ft_op(core, cursor, &param1, &param2);
    if (jump == 1)
        return (jump);
    r3 = MEM_VAL_PC_RELATIVE(jump - 1);
	if (op == e_or)
    	write_to_reg(cursor, r3, param1 | param2);
	else if (op == e_and)
		write_to_reg(cursor, r3, param1 & param2);
	else if (op == e_xor)
		write_to_reg(cursor, r3, param1 ^ param2);
    return (jump);
}

int ft_or(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_or));
}

int ft_xor(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_xor));
}

int ft_and(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_and));
}