/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:14:32 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/08 18:22:08 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int load_players(t_core *core)
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