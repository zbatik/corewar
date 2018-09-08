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
		ft_putendl("./corewar [-dump nbr_cycles] [[-n number] champion1.cor] ...");
		return (1);
	}
	ft_putendl("Init data");
	init_core(&core);
	ft_putendl("Parse input");
	parse_input(&core, c - 1, v + 1);
	ft_putendl("Set players");
	creat_players(&core);
	ft_putendl("Print");
	print_players(&core);
}