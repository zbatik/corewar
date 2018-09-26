/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_form_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:54:18 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 14:55:14 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_player		*get_player_from_num(t_core *core, int player_num)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		if (core->players[i].num == player_num)
			return (&core->players[i]);
	}
	return (NULL);
}