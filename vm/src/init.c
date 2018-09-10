/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:12:42 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/07 18:07:22 by zbatik           ###   ########.fr       */
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

    core->process = NULL;
	core->dump = 0;
	core->cycles_to_dump = -1;
	core->num_players = 0;
	i = -1;
	while (++i < MAX_PLAYERS)
		init_player(&(core->players[i]));
    return (1);
}	