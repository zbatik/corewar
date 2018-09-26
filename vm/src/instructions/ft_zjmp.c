/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:42:12 by zbatik           ###   ########.fr       */
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
		jump = get_dir(core, cursor, 1, e_zjmp) % IDX_MOD;
		cursor->pc = PC(jump);
		if (cursor->pc < 0)
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
