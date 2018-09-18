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

# define RRR 0x54 // 0b01010100 //checked with and
# define RIR 0x74 // 0b01110100 //checked with and
# define RDR 0x64 // 0b01100100
# define RRD 0x58 // 0b10111000 // changed from B8 due to sti
# define RDD 0x68 // first example sti
# define RID 0x78 // first example sti
# define IRR 0xD4 // 0b11010100
# define IIR 0xF4 // 0b11110100
# define IDR 0xE4 // 0b11100100
# define DRR 0x94 // 0b10010100 //checked with and
# define DIR 0xB4 // 0b10110100 //checked with and
# define DDR 0xA4 // 0b10100100
# define IR  0xD0 // 0b11010000 // checked with ld
# define DR  0x90 // 0b10010000 // checked with ld
# define RI  0x70 // checked with st
# define RR  0x50 // checked with st

# define B_RRR 5    // checked with ldi
# define B_RIR 6	// checked with sti
# define B_RDR 6	// checked with ldi
# define B_RRD 6	// checked with sti	
# define B_RDD 7	// checked with sti
# define B_RID 7	// checked with sti
# define B_IRR 6	// checked with ldi
# define B_IIR 1 // WRONG PLEASE CHANGE!!!
# define B_IDR 7	// checked with ldi
# define B_DRR 6  	// checked with ldi
# define B_DIR 1 // WRONG PLEASE CHANGE!!!
# define B_DDR 7
# define B_IR  7	// checked with ldi
# define B_DR  5	// checked with ldi
# define B_RI  5	// checked with st
# define B_RR  4	// checked with

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