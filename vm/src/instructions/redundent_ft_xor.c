/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:34:01 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 11:29:59 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	ft_xor(t_core *core, t_process *cursor)
{
	int param1;
	int param2;
	int r3;
	int jump;

	param1 = 0;
	param2 = 0;
	if (DEBUG)
		print_instr_info(core, e_xor, cursor->pc);
	jump = ft_op(core, cursor, &param1, &param2);
	if (jump == 1)
		return (jump);
	r3 = core->mem[cursor->pc + jump - 1];
	write_to_reg(cursor, r3, param1 ^ param2);
	return (jump);
}