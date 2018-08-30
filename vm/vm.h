/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:48:49 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/30 16:57:51 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "libft/includes/libft.h"
#include <stdlib.h>

typedef	struct	s_player
{
	int		num;
	char	*name;
	char	*instr;
	char	*current;
}				t_player;

typedef struct	s_info
{
	char		*reg;
	char		*player_input;
	int			num_players;
	t_player	**players;
}				t_info;


void print_hex(int n, int cl);
void print_mem(char *reg, char *player_intput, int player_num);

#endif
