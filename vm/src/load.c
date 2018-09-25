/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:14:32 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:05:04 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	set_player_nums(t_core *core, t_player *player)
{
	t_opnum	op;
	int 	pos;
	t_byte	*player_num;
	unsigned int    player_num_int;
	int skip;

	pos = player->start_pos;
	while (pos < (int)player->start_pos + player->size)
	{
		op = core->mem[pos];
		if (op == e_live)
		{
			player_num_int = rev_endian(player->num);
			player_num = (t_byte*)&player_num_int;
			ft_bytencpy(core->mem + pos + 1, player_num, 4);
		}
		skip = byte_counter(core, pos, core->mem[pos]);
		if (skip == 1)
			ft_puterror("Error: Oops problem copying in player numbers");
		pos += skip;
	}
}

static int	load_players(t_core *core)
{
	int			i;
	int			j;
	t_player	player;

	i = -1;

	while (++i < core->num_players)
	{
		player = core->players[i];
		j = -1;
		while (++j < player.size)
		{
			core->mem[(player.start_pos + j) % MEM_SIZE] = player.program[j];
			core->colouring[player.start_pos + j] = i + 1;
		}
		set_player_nums(core, &player);
	}
	return (1);
}

static int	init_cursors(t_core *core)
{
	int i;
	int pc;
	int r1;

	i = 0;
	while (i < core->num_players)
	{
		pc = core->players[core->num_players - i - 1].start_pos;
		r1 = core->players[core->num_players - i - 1].num;
		process_add(&core->processes[i], pc, r1, i);
		update_cycles_to_execute(core->mem[pc], &core->processes[i]);
		core->num_processes += 1;
		i++;
	}
	return (1);
}

int			load(t_core *core)
{
	load_players(core);
	init_cursors(core);
	return (1);
}