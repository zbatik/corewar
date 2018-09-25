/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:31:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:47:44 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	process_add(t_process *cursor, int pc, int player_num, int ind)
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

void	set_cursor_info(t_core *core, t_process *cursor, t_process *new, int pc)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		ft_bytencpy(new->reg[i], cursor->reg[i], REG_SIZE);
	new->carry = cursor->carry;
	new->cycles_to_execute = index_opinfo(core->mem[pc]).cycles;
	new->alive = 1;
	core->num_processes += 1;
}

void	duplicate_process(t_core *core, t_process *cursor, int jump)
{
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
		set_cursor_info(core, cursor, new_cursor, pc);
	}
	else
	{
		if (PBP)
			ft_putendl_cl("process limit reached", lr);
	}
}
