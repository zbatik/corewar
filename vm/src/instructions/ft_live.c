/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:58:10 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 16:33:02 by zbatik           ###   ########.fr       */
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
    int byte_count;
 
    byte_count = general_processing(core, cursor, e_live);
    player_num = byte_to_int(MEM_PNT_PC_RELATIVE(1), 4);
    player = get_player_from_num(core, player_num);
    if (player == NULL)
    { 
        ft_putendl("corrupted player number");
        return (1);
    }
    if (core->pbp || 1) // HELLO PLEASE REMOVE THE 1
    {
        ft_putstr_cl("player number: ", g);
        ft_putnbr_cl(player_num, g);
        ft_putstr_cl(" (", g);
        ft_putstr_cl(player->name, g);
        ft_putstr_cl(") is alive!\n", g);
    }
    player->alive = 1;
    if (!player->dead)
    { 
        core->count.lives += 1;
        core->last_alive = player_num;
    }
    return (byte_count);
}