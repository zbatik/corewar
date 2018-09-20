/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cycle_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:15:41 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/20 14:24:31 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	num_alive(t_core *core)
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

static void	check_alive(t_core *core)
{
	int			i;
	t_player	*player;

	i = -1;
	while (++i < core->num_players)
	{
		player = &core->players[i];
		if (!player->dead)
		{
			if (player->alive)
			{
				if (core->pbp)
					ft_printf(1, g, "player %d (%s) is still alive\n", player->num, player->name);
			}
			else
			{
				if (core->pbp)
					ft_printf(1, r, "player %d (%s) died this round\n", player->num, player->name);
				player->dead = 1;
				player->alive = 0;
			}
		}
		player->alive = 0;
	}
}

void	end_cycle_checks_checks(t_core *core)
{
	char *winner_name;

	check_alive(core);
	if (core->pbp)
		print_cylce_info(core);
	if (num_alive(core) == 0 || core->count.cycles_to_die <= 0)
	{
		winner_name = get_player_from_num(core, core->last_alive)->name;
		ft_printf(1, g, "player %d (%s) is the winner!\n", core->last_alive, winner_name);
		exit(0);
	}
	if (core->checks >= MAX_CHECKS || core->count.lives >= NBR_LIVE)
	{
		core->count.cycles_to_die -= CYCLE_DELTA;
		core->checks = 0;
	}
	else
		core->checks += 1;
	core->count.lives = 0;
	core->count.cycles += 1;
}