/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:58:10 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 11:42:36 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static t_player *get_player_from_num(t_core *core, int player_num)
{
    int i;

    i = -1;
    while (++i < MAX_PLAYERS)
    {
        if (core->players[i].num == player_num)
            return (&core->players[i]);
    }
    return (NULL);
}

int ft_live(t_core *core, t_process *cursor)
{    
    int player_num;
    t_player *player;

    general_processing(core, cursor, e_live);
    player_num = byte_to_int(MEM_PNT_PC_RELATIVE(1), 4);
    player = get_player_from_num(core, player_num);
    if (player == NULL)
    {
        ft_putendl("corrupted player number");
        return (1);
    }
    if (player->alive)
    {
        player->live_count += 1;
        core->last_alive = player_num;
    }
    return (5);
}