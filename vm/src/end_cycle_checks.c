/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_cycle_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:15:41 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 14:49:11 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	checks(t_core *core)
{
	if (core->checks >= MAX_CHECKS || core->count.lives >= NBR_LIVE)
	{
		core->count.cycles_to_die -= CYCLE_DELTA;
		core->checks = 0;
	}
	else
		core->checks += 1;
}

void		end_cycle_checks_checks(t_core *core)
{
	t_player *winner;

	check_players_alive(core);
	check_cursors_alive(core);
	if (PBP)
		print_cylce_info(core);
	if (num_players_alive(core) == 0 || core->count.cycles_to_die <= 0
		|| core->num_processes == 0)
	{
		winner = get_player_from_num(core, core->last_alive);
		if (winner == NULL)
			ft_putendl_cl("No winner, no player called alive", r);
		else
			ft_printf(1, g, "player %d (%s) is the winner!\n",
			winner->num, winner->name);
		exit(0);
	}
	checks(core);
	core->count.lives = 0;
	core->count.cycles += 1;
}
