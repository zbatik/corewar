/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:48:49 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/06 18:32:05 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "../../shared/includes/shared.h"

typedef	struct	s_player
{
	int		num;
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	int		size;
	char	*program;
	int		start_pos;
}				t_player;

typedef struct	s_process
{
	int	pc;
	int reg[REG_NUMBER];
	t_bool carry;
	struct s_process *next;
}				t_process;

typedef struct	s_info
{
	char		*player_input;
	int			num_players;
	t_player	**players;

}				t_info;

int read_file(char *file_name, t_player *player);
void	print_player(t_player *player);

void print_hex(int n, int cl);
void print_mem(char *reg, char *player_intput, int player_num);

#endif
