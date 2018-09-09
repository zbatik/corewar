/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:43:52 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/09 16:36:40 by zbatik           ###   ########.fr       */
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
    int move;

    i = -1;
    while (++i < core->num_processes)
    {
        move = execute_pc(&core->processes[i]);
        core->cursor[core->processes[i].pc - move] = 0;
        core->cursor[core->processes[i].pc] = 1;
    }
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
    else
        move = 0;
    return (move);
}

int game_loop(t_core *core)
{
    int i;
    char *line;

    i = -1;
    while (++i < core->cycles_to_die)
    {
        get_next_line(0, &line);
        ft_strdel(&line);
        execute_pcs(core);
        core->cycles_to_die -= CYCLE_DELTA;
    }
}