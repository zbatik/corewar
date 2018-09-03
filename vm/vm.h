/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:48:49 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/03 17:56:30 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "libft/includes/libft.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef unsigned char	t_byte;

typedef struct	s_player
{
	int		num;
	t_byte	champ[CHAMP_MAX_SIZE];
	int		champ_size;
	int		start_ind;
	char	name[PROG_NAME_LENGTH + 1];
	char	comment[COMMENT_LENGTH + 1];
	int		reg[REG_NUMBER];
}				t_player;

typedef struct	s_core
{
	int			num_players;
	t_player	**players;
	t_byte		reg[MEM_SIZE];
	t_byte		colouring[MEM_SIZE];
	int			pc;
	t_bool		carry;
}				t_core;

enum {
	e_live,
	e_ld,
	e_st,
	e_add,
	e_sub,
	e_and,
	e_or,
	e_xor,
	e_zjmp,
	e_ldi,
	e_sti,
	e_fork,
	e_lld,
	e_lldi,
	e_lfork,
	e_aff,
	e_null,
};

/*
static void (*g_func_ptr[17])(t_env *e, t_cursor *cursor) =
{
	ft_live, ft_live, ft_ld, ft_st, ft_add, ft_sub, ft_and, ft_or,
	ft_xor, ft_zjmp, ft_ldi, ft_sti, ft_fork, ft_lld, ft_lldi,
	ft_lfork, ft_aff
};
*/
void execute(t_byte *reg, int pc);
void print_hex(int n, int cl);
void print_mem(t_byte *reg, t_byte *colouring);
void read_player_bin(char *cor_file);

/*
**	player functions
*/

t_player	*new_player(int n, char *name, char *comment);
void	add_player_bytecode(t_player *pX, t_byte *champ, t_byte champ_size);
void	load_players(t_core *core, int *start_indsi);

#endif
