/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 03:11:19 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	ft_zjmp(t_core *core, t_process *cursor)
{
	int jump;
	int byte_count;

	byte_count = general_processing(core, cursor, e_zjmp);
	if (cursor->carry)
	{
		jump = convert_bytes_to_int(core, PC(1), 2) % IDX_MOD;
		//core->cursor[PC(0)] = 0;
		cursor->pc = PC(jump);
		if (PC(0) < 0)
			cursor->pc += MEM_SIZE;
		if (PBP)
			ft_printf(1, na, "jumped cursor pc + %d\n", jump);
		return (0);
	}
	else
	{
		if (PBP)
			ft_putendl_cl("carry off, no action", lr);
		return (byte_count);
	}
}
