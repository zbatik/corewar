/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:31:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/23 17:07:50 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void    process_add(t_process *cursor, int pc, int player_num, int ind)
{
    int		i;
    
    cursor->id = ind;
    cursor->pc = pc;
	cursor->alive = 0;
    cursor->carry = 0;
    cpy_int_to_reg(cursor, player_num, 1);
    i = 1;
    while (++i <= REG_NUMBER)
		cpy_int_to_reg(cursor, 0, i);
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
		pc = PC(jump);
		if (pc < 0)
			pc += MEM_SIZE;
		new_cursor = &(core->processes[num_proc]);
		process_add(new_cursor, pc, 0, num_proc);
		i = -1;
   		while (++i < REG_NUMBER)
        	ft_bytencpy(new_cursor->reg[i] , cursor->reg[i], REG_SIZE);
		new_cursor->carry = cursor->carry;
		new_cursor->cycles_to_execute = index_opinfo(core->mem[pc]).cycles;
		new_cursor->alive = 1;
		core->num_processes += 1;
	}
	else
	{
		if (PBP)
			ft_putendl_cl("process limit reached", lr);
	}
}