/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 18:14:32 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 18:18:57 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void set_player_nums(t_core *core, t_player *player)
{
	int		i;
	t_opnum	op;
	int 	pos;
	t_byte	*player_num;

	i = -1;
	ft_putendl(player->name);
	pos = player->start_pos;
	while (pos < player->size)
    {
	//	print_mem(core->mem, core->colouring, core->cursor);
		op = core->mem[pos];
		ft_putstr("op: ");
		ft_putnbr(op);
		ft_putchar('\n');
			ft_putstr("pos: ");
		ft_putnbr(pos);
		ft_putchar('\n');
		if (op == e_live)
		{
			ft_putendl_cl(index_opinfo(op).instruction, g);
			player_num = (t_byte*)&player->name; 
			ft_bytencpy(core->mem + pos + 1, player_num, 4);
			pos = pos + 5;
		}
		else if (op >= 0x02 && op <= 0x10)
		{	
			ft_putendl_cl(index_opinfo(op).instruction, g);
			ft_putstr("skip: ");
			ft_putnbr(byte_counter(core, pos, core->mem[pos]));
			ft_putchar('\n');
			pos += byte_counter(core, pos, core->mem[pos]);
		}
		else
		{
			ft_puterror("Error: Oops problem copying in player numbers");
			pos++;
		}
		ft_putendl("");
    }
}

static int load_players(t_core *core)
{
    int         i;
    int         j;
    t_player    player;

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
	exit(0);
    return (1);
}

/*
**  int_cursors
**  __________
**  the last player loaded into the memory is given 
**  the first process. 
*/

static int init_cursors(t_core *core)
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
        core->cursor[core->players[i].start_pos] = 1;
        core->num_processes += 1;
        i++;
    }
    return (1);
}

int load(t_core *core)
{
    load_players(core);
    init_cursors(core);
    return (1);
}