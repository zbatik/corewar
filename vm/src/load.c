/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:14:32 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/09 13:27:16 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int load_players(t_core *core)
{
    int         i;
    t_player    player;

    i = -1;
    while (++i < core->num_players)
    {
        player = core->players[i];
        ft_strncpy((char*)(core->mem + player.start_pos), 
            (char*)player.program, player.size);
    }
    return (1);
}

static int init_cursors(t_core *core)
{
    int         i;
    t_process   *cursor;

    i = core->num_players;
    while (--i >= 0)
    {
        core->num_processes += 1;
        cursor = process_new(core->players[i].start_pos, core->players[i].num);
        process_add(&core->processes, cursor);
    }
    return (1);
}

int load(t_core *core)
{
    load_players(core);
    init_cursors(core);
    return (1);
}