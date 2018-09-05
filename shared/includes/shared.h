/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:40:04 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/05 17:34:44 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

#include "../libft/includes/libft.h"
#include "op.h"

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

typedef struct s_inst_args
{
	t_arg_type	arg1;
	t_arg_type	arg2;
	t_arg_type	arg3;
	t_arg_type	arg4;
}				t_inst_args;

typedef struct	s_opinfo
{
	char		instruction[5];
	short		num_args;
	t_byte		arg_types[MAX_ARGS_NUMBER];
	short		op_number;
	int			cycles;
	char		*description;
	t_bool		arg_encoding_byte;		/* could be wrong */
	t_bool		modifies_carry;   		/* could be wrong */
}				t_opinfo;

#endif