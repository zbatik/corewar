/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/19 16:21:34 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int convert_to_int(t_core *core, t_process *cursor)
{
	t_byte	jump_bytes[4];
	int		start;
	int		i;
	int		jump;

	start = cursor->pc - 1;
	if (start < 0)
		start = start + MEM_SIZE;
	i = -1;
	while (++i < 4)
		jump_bytes[i] = core->mem[(start + i) % MEM_SIZE];
	jump_bytes[0] = 0;
	jump_bytes[1] = 0;
	jump = rev_endian(*(int*)jump_bytes);
	if (jump > 32768)
		jump -= 65536;
	return (jump);
}

int	ft_zjmp(t_core *core, t_process *cursor)
{
	int jump;
	

	general_processing(core, cursor, e_zjmp);
	if (cursor->carry)
	{
		jump = convert_to_int(core, cursor);
		core->cursor[cursor->pc] = 0;
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
