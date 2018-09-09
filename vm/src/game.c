/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:43:52 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/09 16:27:53 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int update_cycles_to_execute(t_byte current, t_process *cursor)
{
    if (current >= 0x00 && current <= 0x10)
        cursor->cycles_to_execute = (index_opinfo(current)).cycles;
    else
        cursor->cycles_to_execute = 1;
}

static int execute_pcs(t_core *core)
{
    int i;

    i = -1;
    while (++i < num_processes)
        execute_pc(&core->num_processes[i]);
    return (1);
}

static int execute_pc(t_process *cursor, t_byte *mem)
{
    int move;

    cursor->cycles_to_execute -= 1;
    if (cursor->cycles_to_execute == 0)
    {
        if (mem[cursor->pc] >= 0x00 && mem[cursor->pc] <= 0x10)
            move = instructon_pointer[mem[cursor->pc]];
        else
            move = 1;
        cursor->pc = (cursor->pc + move) % MEM_SIZE;
        update_cycles_to_execute(mem[cursor->pc], cursor);
    }
}

int game_loop(t_core *core)
{
    int i;

    i = -1;
    while (++i < core->cycles_to_die)
    {
        execute_pcs(t_core *core)
        core->cycles_to_die -= CYCLE_DELTA;
    }
}