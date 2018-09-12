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
		while (++i < REG_NUMBER)
		{
			printf("r%d: %x (or %d)\n", i + 1, 
			*(int*)core->processes[j].reg[i],
			 *(int*)core->processes[j].reg[i]);
		}
	}
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

void	print_cursor_info(t_process *cursor)
{
	ft_putstr("carry: ");
	ft_putnbr(cursor->carry);
	ft_putchar('\n');
	ft_putstr("cycles_to_execute: ");
	ft_putnbr(cursor->cycles_to_execute);
	ft_putchar('\n');
	ft_putstr("id: ");
	ft_putnbr(cursor->id);
	ft_putchar('\n');
	ft_putstr("pc: ");
	ft_putnbr(cursor->pc);
	ft_putchar('\n');
}

void	print_cylce_info(t_core *core, int current)
{
	ft_putstr("cycles to die: ");
	ft_putnbr(current);
	ft_putstr(" of ");
	ft_putnbr(core->cycles_to_die);
	ft_putchar('\n');
}

void	print_players(t_core *core)
{
	int i;

	i = -1;
	ft_putendl_fd("\tPLAYER_BREAKDOWN:", core->fd);
	ft_putstr_fd("Number Players: ", core->fd);
	ft_putnbr_fd(core->num_players, core->fd);
	ft_putchar_fd('\n', core->fd);
	while (++i < core->num_players)
		print_player(&core->players[i], core->fd);
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
	//	ft_putstr_fd("Program:", fd);
	//	for (int i = 0; i < player->size; i++)
	//		fprintf(fd, "%x ", player->program[i]); 
		ft_putstr_fd("Start Pos: ", fd);
		ft_putnbr_fd(player->start_pos, fd);
		ft_putchar_fd('\n', fd);
}