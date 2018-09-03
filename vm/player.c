/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 12:31:48 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/03 17:08:28 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_player	*new_player(int n, char *name, char *comment)
{
	t_player	*pX;
	int			i;

	pX = malloc(sizeof(pX));
	pX->num = n;
	ft_strcpy((char*)pX->name, name);
	ft_strcpy(pX->comment, comment);
	i = -1;
	while (++i < REG_NUMBER)
		pX->reg[i] = 0;
	pX->reg[0] = n;
	return (pX);
}

void	add_player_bytecode(t_player *pX, t_byte *champ, t_byte champ_size)
{
	ft_strcpy((char*)pX->champ, (char*)champ);
	pX->champ_size = champ_size;
}

void	load_players(t_core *core, int *start_inds)
{
	int i;
	int j;
	t_player *player;

	i = -1;
	while (++i < core->num_players)
	{
		player = core->players[i];
		j = -1;
		while (++j < player->champ_size)
		{
			core->reg[start_inds[i] + j] = player->champ[j];
			core->colouring[start_inds[i] + j] = player->num + 1;
		}
	}
}
