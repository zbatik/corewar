/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:22:55 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:03:20 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	pc_option(t_core *core, char *line)
{
	int pc_num;

	pc_num = ft_atoi(line + 8);
	if (pc_num >= core->num_processes)
		ft_putendl("no such process");
	else
		print_cursor_info(core, &core->processes[pc_num]);
}

static void	info_mode(t_core *core)
{
	char	*line;

	ft_putendl_cl("[INFO MODE]", c);
	ft_putendl_cl("[type 'exit' to continue gameplay]", c);
	while (1)
	{
		get_next_line(0, &line);
		if (ft_strequ(line, "print players"))
			print_players(core);
		else if (ft_strnequ(line, "print pc ", 8))
			pc_option(core, line);
		else if (ft_strequ(line, "info off"))
			break ;
		else if (*line == 0)
			;
		else
			ft_putendl("unknown command");
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

void		interactive(t_core *core)
{
	char *line;

	if (core->interactive)
	{
		print_mem(core);
		get_next_line(0, &line);
		if (ft_strequ(line, "interactive off"))
			core->interactive = 0;
		else if (ft_strequ(line, "info on"))
			info_mode(core);
		else if (*line == 0)
			;
		else
			ft_putendl("unknown option");
		ft_strdel(&line);
	}
}
