/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:31:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/20 16:21:11 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void    process_add(t_process *cursor, int pc, int player_num, int ind)
{
    int i;
    
    cursor->id = ind;
    cursor->pc = pc;
    cursor->carry = 0;
    write_to_reg(cursor, 0, rev_endian(player_num));
    i = 0;
    while (++i < REG_NUMBER)
        write_to_reg(cursor, i, 0);
}

void	duplicate_process(t_core *core, t_process *cursor, int jump)
{
	int			i;
	int			pc;
	int			num_proc;
	t_process	*new_cursor;

	num_proc = core->num_processes;
	if (num_proc < MEM_SIZE)
	{
		pc = (cursor->pc + jump) % MEM_SIZE;
		if (pc < 0)
			pc += MEM_SIZE;
		new_cursor = &(core->processes[num_proc]);
		process_add(new_cursor, pc, 0, num_proc);
		i = -1;
   		while (++i < REG_NUMBER)
        	ft_bytencpy(new_cursor->reg[i] , cursor->reg[i], REG_SIZE);
		new_cursor->carry = cursor->carry;
	}
	else
	{
		if (core->pbp)
			ft_putendl_cl("process limit reached", lr);
	}
}