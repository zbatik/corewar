/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:43:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/03 18:05:51 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
/*
int	strtohex(char *hex)
{
	char	*hexstr;
	int		n;

	hexstr = "0123456789abcdef";
	if (ft_strlen(hex) != 2)
	{
		ft_puterror("Invaild hex input");
		exit(-1);
	}
	n = ft_indexcin(hex[0], e
	
}
*/
t_core *init_corewar(int num_players)
{
	t_core *core;
	int		i;

	core = (t_core*)malloc(sizeof(core));
	i = -1;
	core->reg[0] = 3;
//	core->reg = malloc(MEM_SIZE);
//	core->colouring = malloc(MEM_SIZE);
//	while (++i < 200)
//	{
//		core->reg[i] = 1;
//		core->colouring[i] = 0;
//	}
//	ft_bzero(core->reg, MEM_SIZE);
//	ft_bzero(core->colouring, MEM_SIZE);
	core->num_players = num_players;
	core->players = malloc(sizeof(core->players) * (num_players + 1));
	i = -1; 
	while (++i < num_players + 1)
		core->players[i] = NULL;
	ft_putendl_cl("Initialisied Battle Field Memory", c);
	return (core);
}

int main(void)
{
	t_core		*core;
//	int		start_inds[4] = {0, 400, 0, 0};
	//unsigned int         number;

	int num_players = 2;
	core = init_corewar(num_players);
	core->num_players = 2;
	t_byte inst[] = {1, 0, 0, 0, 1};
	core->players[0] = new_player(1, "zack", "comment");
	core->players[1] = new_player(2, "zork", "comment");
	add_player_bytecode(core->players[0], inst, 5);
	add_player_bytecode(core->players[1], inst, 5);
//	load_players(core, start_inds);
	print_mem(core->reg, core->colouring);
	

/*
	ft_putendl("Enter player starting regester:");
	scanf("%d", &start_reg);

	ft_putendl("Enter player length:");
	scanf("%d", &player_len);
	
	ft_putendl_cl("Enter player one byte at a time:", c);
	int i = -1;
	while (++i < player_len) 
	{
		scanf("%x", &number);
		reg[start_reg % MEM_SIZE] = number;
		colouring[start_reg % MEM_SIZE] = g;
		start_reg++;
	}
	
	ft_putendl("Enter player regester to execute:");
	scanf("%d", &exec_reg);

	ft_putendl("View Core [y = 1/n = 0]");
	int yn;
	scanf("%d", &yn);
	if (yn == 1)
		print_mem(reg, colouring);
	execute(reg, exec_reg);
	*/
}
