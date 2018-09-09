/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:12:42 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/09 13:19:05 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	init_player(t_player *player)
{
	player->file_name = NULL;
	ft_bzero(player->name, PROG_NAME_LENGTH + 1);
	ft_bzero(player->comment, COMMENT_LENGTH + 1);
	player->size = 0;
	player->num = -1;
	ft_bzero(player->program, CHAMP_MAX_SIZE);
	player->start_pos = 0;
	return (1);
}

int init_core(t_core *core)
{
	int i;

    core->processes = NULL;
	core->num_processes = 0;
	core->dump = 0;
	core->cycles_to_dump = -1;
	core->num_players = 0;
	ft_bzero(core->mem, MEM_SIZE);
	ft_bzero(core->colouring, MEM_SIZE);
	i = -1;
	while (++i < MAX_PLAYERS)
		init_player(&(core->players[i]));
    return (1);
}	