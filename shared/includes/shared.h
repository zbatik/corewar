/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:40:04 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/06 18:58:46 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

#include "../libft/includes/libft.h"
#include "op.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


# define TRUE 1
# define FALSE 0

# define RRR 0x54 // 0b01010100
# define RIR 0x74 // 0b01110100
# define RDR 0x64 // 0b01100100
# define IRR 0xD4 // 0b11010100
# define IIR 0xF4 // 0b11110100
# define IDR 0xE4 // 0b11100100
# define DRR 0x94 // 0b10010100
# define DIR 0xB4 // 0b10110100
# define DDR 0xA4 // 0b10100100
# define IR  0xD0 // 0b11010000
# define DR  0x90 // 0b10010000
# define RI  0x70
# define RR  0x50

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
} t_opnum;

typedef struct	s_opinfo
{
	char		instruction[5];
	short		num_args;
	t_byte		arg_types[MAX_ARGS_NUMBER];
	short		op_number;
	int			cycles;
	char		description[128];
	t_bool		arg_encoding_byte;		/* could be wrong */
	t_bool		modifies_carry;   		/* could be wrong */
}				t_opinfo;

t_opinfo	index_opinfo(t_opnum op_index);
unsigned int rev_endian(unsigned int num);

#endif