/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:48:49 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/06 18:56:39 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "../../shared/includes/shared.h"

typedef	struct	s_player
{
	char	*file_name;
	int		num;
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	int		size;
	char	program[CHAMP_MAX_SIZE];
	int		start_pos;
}				t_player;

typedef struct	s_process
{
	int		pc;

	int reg[REG_NUMBER];
	t_bool carry;
	struct s_process *next;
}				t_process;

typedef struct	s_core
{
	t_process	*process;
	t_bool		dump;
	int			cycles_to_dump;
	int			num_players;
	t_player	players[MAX_PLAYERS];
	char		mem[MEM_SIZE];
	char		colouring[MEM_SIZE];
}				t_core;

int read_file(char *file_name, t_player *player);

int parse_input(t_core *core, int c, char **v);
void exit_on_error(char *error_msg);
int init_core(t_core *core);
int creat_players(t_core *core);

void	print_parsed_info(t_core *core);
void	print_players(t_core *core);
void	print_player(t_player *player);
void print_hex(int n, int cl);
void print_mem(char *reg, char *player_intput, int player_num);

#endif
