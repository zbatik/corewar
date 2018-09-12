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

# define DEBUG 1

typedef	struct	s_player
{
	char	*file_name;
	int		num;
	t_bool	alive;
	int		live_count;
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	int		size;
	t_byte	program[CHAMP_MAX_SIZE];
	unsigned int		start_pos;
}				t_player;

typedef struct	s_process
{
	int					id;
	int					pc;
	int					cycles_to_execute;
	t_byte				reg[REG_NUMBER][REG_SIZE];
	t_bool 				carry;
}				t_process;

typedef struct	s_core
{
	int 		(*instructon_fn[16]) (struct s_core *core, t_process *cursor);
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
	int			fd;
}				t_core;

typedef enum {
	rrr,
	rir,
	rdr,
	irr,
	idr,
	drr,
	dir,
	ddr,
	ir,
	dr,
}		t_para_comb;

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
void    process_add(t_process *cursor, int pc, int player_num, int ind);

/*
**	game.c
*/
int game_loop(t_core *core);
int update_cycles_to_execute(t_byte current, t_process *cursor);

/*
**	disp.c
*/
void	print_instr_info(t_core *core, t_opnum op, int pc);
void	print_cursor_info(t_process *cursor);
void	print_cylce_info(t_core *core, int current);
void	print_parsed_info(t_core *core);
void	print_players(t_core *core);
void	print_player(t_player *player, int fd);
void	print_hex(int n, int cl);
void	print_mem(t_byte *reg, t_byte *colouring, t_byte *cursor);
void	print_processes(t_core *core);

/*
**	exit.c 
*/
void exit_on_error(char *error_msg);

/*
**	helpers.c 
*/
int     byte_to_int(unsigned char *input, int len);
t_bool  valid_reg(int rX);
void    cpy_from_reg(t_core *core, t_byte *reg_entry, int cpy_from);

/*
**	instructions/ 
*/
int ft_live(t_core *core, t_process *cursor);
int ft_ld(t_core *core, t_process *cursor);
int ft_st(t_core *core, t_process *cursor);
int ft_add(t_core *core, t_process *cursor);
int ft_sub(t_core *core, t_process *cursor);
int ft_and(t_core *core, t_process *cursor);
int ft_or(t_core *core, t_process *cursor);
int ft_xor(t_core *core, t_process *cursor);
int ft_zjmp(t_core *core, t_process *cursor);
int ft_ldi(t_core *core, t_process *cursor);
int ft_sti(t_core *core, t_process *cursor);
int ft_fork(t_core *core, t_process *cursor);
int ft_lld(t_core *core, t_process *cursor);
int ft_lldi(t_core *core, t_process *cursor);
int ft_lfork(t_core *core, t_process *cursor);
int ft_aff(t_core *core, t_process *cursor);

#endif
