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

int	main(int c, char **v)
{
	t_core core;

	if (c == 1)
	{
		ft_putstr("./corewar [-pbp play_by_play] [-i interactive_mode] ");
		ft_putstr("[-dump nbr_cycles] [[-n number] champion1.cor] ... ]\n");
		return (1);
	}
	core.fd = open("core.log", O_WRONLY | O_APPEND | O_CREAT, 7777);
	//ft_putendl_fd("Init data", core.fd);
	init_core(&core);
	//ft_putendl_fd("Parse input", core.fd);
	parse_input(&core, c - 1, v + 1);
	//ft_putendl_fd("Set players", core.fd);
	creat_players(&core);
	//print_players(&core);
	//ft_putendl_fd("Load players & init cursors", core.fd);
	load(&core);
	game_loop(&core);
//	print_processes(&core);
	return (1);
}