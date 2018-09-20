/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/20 12:02:48 by zbatik           ###   ########.fr       */
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
		jump = convert_2b_to_int(core, cursor->pc + 1) % IDX_MOD;
		cursor->pc = cursor->pc + jump % MEM_SIZE;
		if (cursor->pc < 0)
			cursor->pc += MEM_SIZE;
		core->cursor[cursor->pc] = 0;
		return (0);
	}
	else
	{
		if (core->pbp)
			ft_putendl_cl("carry off, no action", lr);
		return (byte_count);
	}
}
