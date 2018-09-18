/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cycle_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:15:41 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 16:32:44 by zbatik           ###   ########.fr       */
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
				ft_putstr_cl("player ", g);
				ft_putnbr_cl(player->num, g);
				ft_putendl_cl("is still alive", g);
			}
			else
			{
				ft_putstr_cl("player ", r);
				ft_putnbr_cl(player->num, r);
				ft_putendl_cl(" died this round", r);
				player->dead = 1;
			}
		}
		player->alive = 0;
	}
}

void	end_cycle_checks_checks(t_core *core)
{
	check_alive(core);
		print_cylce_info(core);
	if (core->pbp)
	{
		print_cylce_info(core);
	}
	if (num_alive(core) == 0 || core->count.cycles_to_die <= 0)
	{
		ft_putstr_cl("player ", g);
		ft_putnbr_cl(core->last_alive, g);
		ft_putendl_cl(" is the winner!", g);
		exit(0);
	}
	if (core->checks >= MAX_CHECKS || core->count.lives >= NBR_LIVE)
		core->count.cycles_to_die -= CYCLE_DELTA;
	else
		core->checks += 1;
}