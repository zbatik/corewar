/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:48:49 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/02 13:13:47 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include "libft/includes/libft.h"
#include "op.h"
#include <stdlib.h>
#include <stdio.h>

typedef unsigned char	t_byte;

enum {
	live,
	ld,
	st,
	add,
	sub,
	and,
	or,
	xor,
	zjmp,
	ldi,
	sti,
	fork,
	lld,
	lldi,
	lfork,
	aff,
	null,
};

void print_hex(int n, int cl);
void print_mem(t_byte *reg, char *player_intput);

#endif
