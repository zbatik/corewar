/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:43:52 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 15:50:06 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			update_cycles_to_execute(t_byte current, t_process *cursor)
{
	if (current >= 0x01 && current <= 0x10)
		cursor->cycles_to_execute = (index_opinfo(current)).cycles;
	else
		cursor->cycles_to_execute = 1;
	return (1);
}

static int	execute_pc(t_core *core, t_process *cursor)
{
	int move;

	if (cursor->cycles_to_execute == 0)
	{
		if (core->mem[cursor->pc] >= 0x01 && core->mem[cursor->pc] <= 0x10)
			move = core->instructon_fn[core->mem[cursor->pc] - 1](core, cursor);
		else
			move = 1;
		cursor->pc = (cursor->pc + move) % MEM_SIZE;
		update_cycles_to_execute(core->mem[cursor->pc], cursor);
	}
	else
		move = 0;
	cursor->cycles_to_execute -= 1;
	return (move);
}

static int	execute_pcs(t_core *core)
{
	int i;
	int move;

	i = -1;
	while (++i < core->num_processes)
		move = execute_pc(core, &core->processes[i]);
	return (1);
}

static void	dump(t_core *core)
{
	if (core->dump)
	{
		if (core->count.total_turns == core->cycles_to_dump)
		{
			print_mem(core);
			exit(0);
		}
	}
}

int			game_loop(t_core *core)
{
	int i;

	while (1)
	{
		i = -1;
		while (++i < core->count.cycles_to_die)
		{
			interactive(core);
			execute_pcs(core);
			dump(core);
			core->count.total_turns += 1;
		}
		end_cycle_checks_checks(core);
	}
	return (1);
}
