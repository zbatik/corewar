/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:26:33 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/03 16:05:22 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void read_player_bin(char *cor_file)
{
//	t_byte			buffer[CHAMP_MAX_SIZE];
	t_byte	magic[4];
	FILE *ptr;

	ptr = fopen(cor_file, "rb");
	fread(magic, 4, 1, ptr);
	ft_putendl((char*)magic);
	if ((unsigned int)magic == COREWAR_EXEC_MAGIC)
		ft_putendl("success!");
	else
		ft_putendl("Oops");
	//	fread(buffer, MAX_CHAM_SIZE, 1, ptr);
	
}
