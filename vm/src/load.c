/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:14:32 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/09 16:27:14 by zbatik           ###   ########.fr       */
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

static int init_cursors(t_core *core)
{
    int         i;
 //   t_process   *cursor;

    i = core->num_players;
    while (--i >= 0)
    {
        process_add(core, core->players[i].start_pos, core->players[i].num);
        core->cursor[core->players[i].start_pos] = 1;
    }
    return (1);
}

int load(t_core *core)
{
    load_players(core);
    init_cursors(core);
    return (1);
}