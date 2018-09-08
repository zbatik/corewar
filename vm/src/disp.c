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

void	print_mem(char *reg, char *player_input, int player_num)
{
	int i;
	int cl;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			ft_putchar('\n');
		cl = (player_input[i] == -1 ? na : player_num);
		print_hex(((char *)reg)[i], cl);
		ft_putchar(' ');
		i++;
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
		printf("player file: |%s|, player num: %d\n", core->players[i].file_name, core->players[i].num);
	}
	printf("_____________\n");
}

void	print_players(t_core *core)
{
	int i;

	i = -1;
	printf("Number Players: %d\n", core->num_players);
	while (++i < core->num_players)
		print_player(&core->players[i]);
}

void	print_player(t_player *player)
{
		printf("___Player_Info___\n");
		printf("Player Number %d\n", player->num);
		printf("Player Name: \"%s\"\n", player->name);
		printf("Player File name: %s\n", player->file_name);
		printf("Comment: \"%s\"\n", player->comment);
		printf("Player Size: %x (in decimal) %d\n", player->size, player->size);
		printf("Program:");
		for (int i = 0; i < player->size; i++)
			printf("%x", player->program[i]);
		printf("\n");
		printf("Start Pos: %d\n", player->start_pos);
}