/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 13:23:43 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	ft_zjmp(t_core *core, t_process *cursor)
{
	int jump;

	general_processing(core, cursor, e_zjmp);
	if (cursor->carry)
	{
		jump = byte_to_int(MEM_PNT_PC_RELATIVE(1), 2);
		cursor->pc = (cursor->pc + (jump % IDX_MOD)) % MEM_SIZE;
		return (0);
	}
	else
	{
		if (core->pbp)
			ft_putendl("carry off, no action");
		return (3);
	}
	
}
