/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:31:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 14:22:33 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		process_add(t_process *cursor, int pc, int player_num, int ind)
{
	int		i;

	cursor->id = ind;
	cursor->pc = pc;
	cursor->alive = 0;
	cursor->dead = 0;
	cursor->carry = 0;
	cpy_int_to_reg(cursor, player_num, 1);
	i = 1;
	while (++i <= REG_NUMBER)
		cpy_int_to_reg(cursor, 0, i);
}

static void	inherit_cursor_info(t_process *cursor, t_process *new)
{
	int i;

	i = -1;
	while (++i < REG_NUMBER)
		ft_bytencpy(new->reg[i], cursor->reg[i], REG_SIZE);
	new->carry = cursor->carry;
	new->alive = 1;
}

static int			available_cursor_ind(t_core *core)
{
	int i;

	i = -1;
	while (++i < MEM_SIZE)
	{
		if (core->processes[i].dead == 1)
			return (i);
	}
	return (-1);
}

int			duplicate_process(t_core *core, t_process *cursor, int pc)
{
	int			ind;
	t_process	*new_cursor;

	ind = available_cursor_ind(core);
	if (ind > 0)
	{
		if (pc < 0)
			pc += MEM_SIZE;
		new_cursor = &(core->processes[ind]);
		process_add(new_cursor, pc, 0, ind);
		update_cycles_to_execute(core->mem[pc % MEM_SIZE], new_cursor);
		inherit_cursor_info(cursor, new_cursor);
		core->num_processes += 1;
		return (1);
	}
	else
	{
		if (PBP)
			ft_putendl_cl("process limit reached", lr);
			return (0);
	}
}
