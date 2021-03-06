/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:58:10 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 14:06:04 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	ft_live(t_core *core, t_process *cursor)
{
	int			num;
	t_player	*player;
	int			byte_count;

	byte_count = general_processing(core, cursor, e_live);
	num = convert_bytes_to_int(core, PC(1), 4);
	player = get_player_from_num(core, num);
	if (player == NULL)
	{
		if (PBP)
			ft_printf(1, lr, "corrupted player number\n");
		return (1);
	}
	if (!player->dead)
	{
		if (PBP)
			ft_printf(1, g, "player %d (%s), is alive\n", num, player->name);
		player->alive = 1;
		core->count.lives += 1;
		core->last_alive = num;
		cursor->alive = 1;
	}
	return (byte_count);
}
