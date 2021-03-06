/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 18:43:33 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 13:35:56 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void		print_instr_info(t_core *core, t_process *cursor, t_opnum op)
{
	t_opnum num;
	char	*instrucntion;

	num = CORE_VAL(0);
	ft_putstr_cl("process id ", b);
	ft_putnbr_cl(cursor->id, c);
	ft_putstr_cl(" with cursor at ", b);
	ft_putnbr_cl(cursor->pc, c);
	ft_putstr_cl(" about to execute\n", b);
	instrucntion = index_opinfo(num).instruction;
	ft_printf(1, c, "recieved instruction: %s\n", instrucntion);
	instrucntion = index_opinfo(op).instruction;
	ft_printf(1, c, "expected intsruction: %s\n", instrucntion);
}

static void	print_reg(t_process *cursor)
{
	int i;
	int rev;

	i = -1;
	while (++i < REG_NUMBER)
	{
		rev = rev_endian(*(int*)cursor->reg[i]);
		ft_printf(1, na, "r%d: %x (or %d)\n", i + 1, rev, rev);
	}
}

void		print_cursor_info(t_core *core, t_process *cursor)
{
	ft_printf(1, na, "id:\t%d\n", cursor->id);
	ft_printf(1, na, "carry:\t%d\n", cursor->carry);
	ft_printf(1, na, "pc location:\t%d\n", cursor->pc);
	ft_printf(1, na, "alive:\t%d\n", cursor->alive);
	ft_putstr("instruction to execute: ");
	ft_putendl((index_opinfo(CORE_VAL(0))).instruction);
	ft_putstr("cycles_to_execute: ");
	ft_putnbr(cursor->cycles_to_execute);
	ft_putchar('\n');
	print_reg(cursor);
}

static void	print_player(t_player *player, int fd)
{
	ft_putendl_fd("___Player_Info___", fd);
	ft_putstr_fd("Player Number", fd);
	ft_putnbr_fd(player->num, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("Player Name: ", fd);
	ft_putendl_fd(player->name, fd);
	ft_putstr_fd("Player File name: ", fd);
	ft_putendl_fd(player->file_name, fd);
	ft_putstr_fd("Comment: ", fd);
	ft_putendl_fd(player->comment, fd);
	ft_putstr_fd("Player Size: ", fd);
	ft_putnbr_fd(player->size, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("Start PC: ", fd);
	ft_putnbr_fd(player->start_pos, fd);
	ft_putchar_fd('\n', fd);
}

void		print_players(t_core *core)
{
	int i;
	int fd;

	fd = 0;
	i = -1;
	ft_putendl_fd("\tPLAYER_BREAKDOWN:", fd);
	ft_putstr_fd("Number Players: ", fd);
	ft_putnbr_fd(core->num_players, fd);
	ft_putchar_fd('\n', fd);
	while (++i < core->num_players)
		print_player(&core->players[i], fd);
}
