/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:10:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:08:13 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	check_duplicate(t_core *core, int player_num)
{
	int i;

	i = -1;
	while (++i < core->num_players)
	{
		if (core->players[i].num == player_num)
			exit_on_error("Error: duplicate player numbers");
	}
}

static int	ft_isposint(char *num)
{
	int n;

	if (!ft_isnumber(num))
		exit_on_error("Error: non-number arg value");
	n = ft_atoi(num);
	if (!ft_isint(num))
		exit_on_error("Error: non-int arg value");
	if (n < 0)
		exit_on_error("Error: negative arg value");
	return (n);
}

static int	parse_flags(t_core *core, int c, char **v)
{
	int skip;

	skip = 0;
	if (ft_strequ(v[0 + skip], "-pbp"))
	{
		core->pbp = 1;
		skip += 1;
	}
	if (ft_strequ(v[0 + skip], "-i"))
	{
		core->interactive = 1;
		skip += 1;
	}
	if (c > 2 + skip)
	{
		if (ft_strequ(v[0 + skip], "-dump"))
		{
			core->dump = 1;
			core->cycles_to_dump = ft_isposint(v[1 + skip]);
			skip += 2;
		}
	}
	return (skip);
}

static int	parse_players(t_core *core, int c, char **v)
{
	int i;
	int player_num;

	i = -1;
	while (++i < c)
	{
		core->num_players += 1;
		if (core->num_players > MAX_PLAYERS)
			exit_on_error("Error: too many players");
		if (ft_strequ(v[i], "-n"))
		{
			i++;
			if (i >= c)
				exit_on_error("Error: invalid argument");
			player_num = ft_isposint(v[i++]);
			if (i >= c)
				exit_on_error("Error: invalid argument");
			check_duplicate(core, player_num);
			core->players[core->num_players - 1].num = player_num;
		}
		core->players[core->num_players - 1].file_name = v[i];
	}
	return (1);
}

int			parse_input(t_core *core, int c, char **v)
{
	int skip;

	skip = parse_flags(core, c, v);
	v = v + skip;
	c = c - skip;
	parse_players(core, c, v);
	return (1);
}
