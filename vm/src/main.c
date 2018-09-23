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
	init_core(&core);
	parse_input(&core, c - 1, v + 1);
	creat_players(&core);
	load(&core);
	game_loop(&core);
	return (1);
}