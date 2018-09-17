/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cycle_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:15:41 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/17 13:05:49 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	num_alive(t_core *core)
{
	int			i;
	int			count;
	t_player	*player;

	count = 0;
	i = -1;
	while (++i < core->num_players)
	{
		player = &core->players[i];
		if (player->alive)
			count++;
	}
	return (count);
}

static void	check_alive(t_core *core)
{
	int i;
	t_player *player;

	i = -1;
	while (++i < core->num_players)
	{
		player = &core->players[i];
		if (player->live_count >= NBR_LIVE)
		{
			ft_putstr_cl("player ", g);
			ft_putnbr_cl(player->num, g);
			ft_putendl_cl("is still alive", g);
		}
		else
		{
			ft_putstr_cl("player ", r);
			ft_putnbr_cl(player->num, r);
			ft_putendl_cl(" died", r);
			player->alive = 0;
		}
		player->live_count = 0;
	}
}

void	end_cycle_checks_checks(t_core *core)
{
	check_alive(core);
	if (num_alive(core) == 0 || core->cycles_to_die <= 0)
	{
		ft_putstr_cl("player ", g);
		ft_putnbr_cl(core->last_alive, g);
		ft_putendl_cl(" is the winner!", g);
		exit(0);
	}
	core->cycle_number += 1;
}