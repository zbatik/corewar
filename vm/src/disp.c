/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:44:00 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/06 18:35:42 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	print_hex(int n, int cl)
{
	char	out[12];
	char	*hex;
	int		i;

	i = 0;
	ft_bzero(out, 12);
	hex = "0123456789abcdef";
	if (n == 0)
		ft_putchar_cl('0', cl);
	while (n != 0)
	{
		out[i] = hex[n % 16];
		n = n / 16;
		i++;
	}
	i = 1;
	if (out[1] == 0)
	{
		ft_putchar_cl('0', cl);
		i--;
	}
	while (out[i])
		ft_putchar_cl(out[i--], cl);
}

void	print_mem(t_byte *reg, t_byte *colouring, t_byte *cursor)
{
	int i;
	//int cl;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			ft_putchar('\n');
		ft_putstr(cursor[i] ? "\033[7m" : "");
		print_hex(reg[i], colouring[i]);
		ft_putstr(cursor[i] ? "\033[m": "");
		ft_putchar(' ');
		i++;
	}
	ft_putendl("");
}

void print_reg(t_process *cursor)
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

void	print_processes(t_core *core)
{
	int j;
	int i;

	j = -1;
	while (++j < core->num_processes)
	{
		printf("_____________\n");
		printf("Process ID: %d\n", j + 1);
		printf("PC: %d\n", core->processes[j].pc);
		printf("Carry: %d\n", core->processes[j].carry);
		i = -1;
		print_reg(&core->processes[j]);
	}
}

void	print_instr_info(t_core *core, t_process *cursor, t_opnum op)
{
	t_opnum num;

	num = MEM_VAL_PC_RELATIVE(0);
	ft_putstr_cl("process id ", b);
	ft_putnbr_cl(cursor->id, c);
	ft_putstr_cl(" with cursor at ", b);
	ft_putnbr_cl(cursor->pc, c);
	ft_putstr_cl(" about to execute\n", b);
	ft_printf(1, c, "recieved instruction: %s\n", index_opinfo(num).instruction);
	ft_printf(1, c, "expected intsruction: %s\n", index_opinfo(op).instruction);
}

void	print_parsed_info(t_core *core)
{	
	printf("___Parsed Data___\n");
	printf("Dump core: %d\n", core->dump);
	if (core->dump)
		printf("after %d cycles\n", core->cycles_to_dump);
	printf("Number Players: %d\n", core->num_players);
	int	i = -1;
	while (++i < core->num_players)
	{
		printf("Player file: |%s|, Player num: %d\n", core->players[i].file_name, core->players[i].num);
	}
	printf("_____________\n");
}

void	print_cursor_info(t_core *core, t_process *cursor)
{
	ft_putstr("id: ");
	ft_putnbr(cursor->id);
	ft_putchar('\n');
	ft_putstr("carry: ");
	ft_putnbr(cursor->carry);
	ft_putchar('\n');
	ft_putstr("pc location: ");
	ft_putnbr(cursor->pc);
	ft_putchar('\n');
	ft_putstr("instruction to execute: ");
 	ft_putendl((index_opinfo(MEM_VAL_PC_RELATIVE(0))).instruction);
	ft_putstr("cycles_to_execute: ");
	ft_putnbr(cursor->cycles_to_execute);
	ft_putchar('\n');
	print_reg(cursor);
	
}



void	print_cylce_info(t_core *core)
{
	ft_printf(1, y, "END OF CYCLE BREAKDOWN\n");
	ft_printf(1, m, "number of processes:\t%d\n", core->num_processes);
	ft_printf(1, m, "round number:\t\t%d\n", core->count.cycles);
	ft_printf(1, m, "totol executed turns:\t%d\n", core->count.total_turns);
	ft_printf(1, m, "cycles to die:\t\t%d\n", core->count.cycles_to_die);
	ft_printf(1, m, "live count this cycle:\t%d\n", core->count.lives);
	ft_printf(1, m, "number players alive:\t%d\n", num_alive(core));
}

void	print_players(t_core *core)
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

void	print_player(t_player *player, int fd)
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