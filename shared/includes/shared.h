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

t_opinfo		index_opinfo(t_opnum op_index);
unsigned int	rev_endian(unsigned int num);
#endif
