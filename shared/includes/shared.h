/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:40:04 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:34:00 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "../libft/includes/libft.h"
# include "op.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

# define RRR 0x54
# define RIR 0x74
# define RDR 0x64
# define RRD 0x58
# define RDD 0x68
# define RID 0x78
# define IRR 0xD4
# define IIR 0xF4
# define IDR 0xE4
# define DRR 0x94
# define DIR 0xB4
# define DDR 0xA4
# define IR  0xD0
# define DR  0x90
# define RI  0x70
# define RR  0x50
# define R   0x40

# define B_RRR 5
# define B_RIR 6
# define B_RDR 8
# define B_RRD 8
# define B_RDD 11
# define B_RID 9
# define B_IRR 6
# define B_IIR 7
# define B_IDR 9
# define B_DRR 8
# define B_DIR 9
# define B_DDR 11
# define B_IR  5
# define B_DR  7
# define B_RI  5
# define B_RR  4
# define B_R   3

typedef unsigned char	t_byte;

typedef enum {
	e_null,
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
}	t_opnum;

typedef struct	s_opinfo
{
	char		instruction[5];
	short		num_args;
	t_byte		arg_types[MAX_ARGS_NUMBER];
	short		op_number;
	int			cycles;
	char		description[128];
	t_bool		modifies_carry;
	t_bool		funky_dir_size;
}				t_opinfo;

static t_opinfo	g_op_tab[18] =
{
	{"null", 0, {0}, 0, 0, "", 0, 0},
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{"null", 0, {0}, 0, 0, "", 0, 0}
};

t_opinfo		index_opinfo(t_opnum op_index);
unsigned int	rev_endian(unsigned int num);
int				is_valid_filename(char *s, char *extension);
#endif
