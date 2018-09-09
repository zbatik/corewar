/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:48:49 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/09 13:51:42 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "../../shared/includes/shared.h"

typedef	struct	s_player
{
	char	*file_name;
	int		num;
	t_bool	alive;
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	int		size;
	t_byte	program[CHAMP_MAX_SIZE];
	unsigned int		start_pos;
}				t_player;

typedef struct	s_process
{
	int					pc;
	int					cycles_to_execute;
	int					reg[REG_SIZE];
	t_bool 				carry;
}				t_process;

typedef struct	s_core
{
	t_process	processes[MEM_SIZE];
	int			num_processes;
	t_bool		dump;
	int			cycles_to_die;
	int			cycles_to_dump;
	int			num_players;
	t_player	players[MAX_PLAYERS];
	t_byte		mem[MEM_SIZE];
	t_byte		colouring[MEM_SIZE];
	t_byte		cursor[MEM_SIZE];
}				t_core;

/*
**	init.c
*/
int init_core(t_core *core);

/*
**	input.c
*/
int parse_input(t_core *core, int c, char **v);

/*
**	players.c
*/
int creat_players(t_core *core);

/*
**	load.c
*/
int load(t_core *core);

/*
**	cursor.c
*/
void    process_add(t_core *core, int pc, int player_num);
//t_process	*process_new(int pc, int player_num);
//void		process_add(t_process **head, t_process *new);
//void		process_del(t_process **head);

/*
**	disp.c
*/
void	print_parsed_info(t_core *core);
void	print_players(t_core *core);
void	print_player(t_player *player);
void	print_hex(int n, int cl);
void	print_mem(t_byte *reg, t_byte *colouring, t_byte *cursor);
void	print_processes(t_core *core);

/*
**	exit.c 
*/
void exit_on_error(char *error_msg);

#endif
