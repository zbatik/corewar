/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:55:44 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/06 17:17:00 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
t_player	*add_player(int num, char *name, char *inst, char *current)
{
	t_player *new_player;
	new_player = malloc(sizeof(new_player));
	new_player->num = num;
	new_player->name = ft_strdup(name);
	new_player->instr = inst;
	new_player->current = current;
	return (new_player);
}

void	load_player(t_player *player, t_info *info, int start)
{
	size_t i;

	i = -1;
	while (++i < ft_strlen(player->instr))
	{
		info->reg[start + i] = player->instr[i];
		info->num_players = 2;
		info->player_input[start + i] = player->num;
	}
}
*/
int	main(int c, char **v)
{
	t_player	*players[MAX_PLAYERS];
	int		num_players;
	int		i;

	i = 0;
	num_players = c - 1;
	while (i++ < num_players)
	{
		players[i] = malloc(sizeof(void*));
		read_file(v[i], players[i]);
	}
	i = 0;
	while (i++ < num_players)
	{
		print_player(players[i]);
	}
	/*
	info = malloc(sizeof(info));
	info->reg = malloc(sizeof(t_byte) * MEM_SIZE);
	ft_bzero(info->reg, MEM_SIZE);
	info->player_input = malloc(sizeof(t_byte) * MEM_SIZE);
	i = -1;
	while (++i < MEM_SIZE)
		info->player_input[i] = -1;
	c = 0;
	*v = 0;
	char *instr = "12312312z";
	load_player(add_player(1, "harry", instr, info->reg), info, 0);
	print_mem(info->reg, info->player_input, 1);
	*/
}
