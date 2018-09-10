/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:14:32 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/10 15:02:20 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int load_players(t_core *core)
{
    int         i;
    int         j;
    t_player    player;

    i = -1;
    while (++i < core->num_players)
    {
        player = core->players[i];
        j = -1;
        while (++j < player.size)
        {
            core->mem[(player.start_pos + j) % MEM_SIZE] = player.program[j];
            core->colouring[player.start_pos + j] = i + 1;
        }
    }
    return (1);
}

/*
**  int_cursors
**  __________
**  the last player loaded into the memory is given 
**  the first process. 
*/

static int init_cursors(t_core *core)
{
    int i;
    int pc;
    int r1;

    i = 0;
    while (i < core->num_players)
    {
        pc = core->players[core->num_players - i - 1].start_pos;
        r1 = core->players[core->num_players - i - 1].num;
        process_add(&core->processes[i], pc, r1, i);
        update_cycles_to_execute(core->mem[pc], &core->processes[i]);
        core->cursor[core->players[i].start_pos] = 1;
        core->num_processes += 1;
        i++;
    }
    return (1);
}

int load(t_core *core)
{
    load_players(core);
    init_cursors(core);
    return (1);
}