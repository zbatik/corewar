/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/19 14:52:25 by zbatik           ###   ########.fr       */
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
		printf("%x %d \n",jump, jump);
		cursor->pc = (cursor->pc + (jump % IDX_MOD)) % MEM_SIZE;
		return (0);
	}
	else
	{
		if (core->pbp)
			ft_putendl_cl("carry off, no action", lr);
		return (3);
	}
	
}
