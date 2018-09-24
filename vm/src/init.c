/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:12:42 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 03:11:36 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	init_fnptr(t_core *core)
{
    core->instructon_fn[0] = ft_live;
    core->instructon_fn[1] = ft_ld;
    core->instructon_fn[2] = ft_st;
    core->instructon_fn[3] = ft_add;
    core->instructon_fn[4] = ft_sub;
    core->instructon_fn[5] = ft_and;
    core->instructon_fn[6] = ft_or;
    core->instructon_fn[7] = ft_xor;
    core->instructon_fn[8] = ft_zjmp;
    core->instructon_fn[9] = ft_ldi;
    core->instructon_fn[10] = ft_sti;
    core->instructon_fn[11] = ft_fork;
    core->instructon_fn[12] = ft_lld;
    core->instructon_fn[13] = ft_lldi;
    core->instructon_fn[14] = ft_lfork;
    core->instructon_fn[15] = ft_aff;
}

static int	init_player(t_player *player)
{
	player->file_name = NULL;
	ft_bzero(player->name, PROG_NAME_LENGTH + 1);
	ft_bzero(player->comment, COMMENT_LENGTH + 1);
	player->alive = 0;
	player->dead = 0;
//	player->live_count = 0;
	player->size = 0;
	player->num = -1;
	ft_bzero(player->program, CHAMP_MAX_SIZE);
	player->start_pos = 0;
	return (1);
}

int init_core(t_core *core)
{
	int i;

	init_fnptr(core);
	core->num_processes = 0;
	core->dump = 0;
	core->interactive = 0;
	core->pbp = 0;
	core->checks = 0;
	core->count.lives = 0;
	core->last_alive = 0;
	core->count.cycles = 0;
	core->count.total_turns = 0;
	core->cycles_to_dump = -1;
	core->count.cycles_to_die = CYCLE_TO_DIE;
	core->num_players = 0;
	ft_bzero(core->mem, MEM_SIZE);
	ft_bzero(core->colouring, MEM_SIZE);
	//ft_bzero(core->cursor, MEM_SIZE);
	i = -1;
	while (++i < MAX_PLAYERS)
		init_player(&(core->players[i]));
    return (1);
}	