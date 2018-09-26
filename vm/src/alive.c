/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:26:43 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 15:04:43 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	check_player_alive(t_core *core, t_player *player)
{
	if (!player->dead)
	{
		if (player->alive)
		{
			if (PBP)
				ft_printf(1, g, "player %d (%s) is still alive\n",
				player->num, player->name);
		}
		else
		{
			if (PBP)
				ft_printf(1, r, "player %d (%s) died this round\n",
				player->num, player->name);
			player->dead = 1;
			player->alive = 0;
		}
	}
}

void		check_players_alive(t_core *core)
{
	int			i;
	t_player	*player;

	i = -1;
	while (++i < core->num_players)
	{
		player = &core->players[i];
		check_player_alive(core, player);
		player->alive = 0;
	}
}

int			num_players_alive(t_core *core)
{
	int			i;
	int			count;
	t_player	*player;

	count = 0;
	i = -1;
	while (++i < core->num_players)
	{
		player = &core->players[i];
		if (!player->dead)
			count++;
	}
	return (count);
}

void		check_cursors_alive(t_core *core)
{
	int			i;
	t_process	*cursor;

	i = -1;
	while (++i < MEM_SIZE)
	{
		cursor = &core->processes[i];
		if (cursor->alive == 0 && cursor->dead == 0)
		{
			if (PBP)
				ft_printf(1, r, "cursor id: %d died\n", cursor->id);
			cursor->dead = 1;
			core->num_processes -= 1;
		}
		cursor->alive = 0;
	}
}
