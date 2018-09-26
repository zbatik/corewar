/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_count1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:12:43 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 15:05:40 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	byte_counter1(t_core *core, int pc, t_opnum op)
{
	t_byte eb;

	eb = core->mem[(pc + 1) % MEM_SIZE];
	if (op == e_live)
		return (5);
	else if (op == e_ld)
		return (bytes_ld_gen(eb));
	else if (op == e_st)
		return (bytes_st(eb));
	else if (op == e_add)
		return (B_RRR);
	else if (op == e_sub)
		return (B_RRR);
	else if (op == e_and)
		return (bytes_or_gen(eb));
	else if (op == e_or)
		return (bytes_or_gen(eb));
	else if (op == e_xor)
		return (bytes_or_gen(eb));
	else if (op == e_zjmp)
		return (3);
	else
		return (1);
}

int	byte_counter2(t_core *core, int pc, t_opnum op)
{
	t_byte eb;

	eb = core->mem[(pc + 1) % MEM_SIZE];
	if (op == e_ldi)
		return (bytes_ldi_gen(eb));
	else if (op == e_sti)
		return (bytes_sti(eb));
	else if (op == e_fork || op == e_lfork)
		return (3);
	else if (op == e_lld)
		return (bytes_ld_gen(eb));
	else if (op == e_lldi)
		return (bytes_ldi_gen(eb));
	else if (op == e_aff)
		return (3);
	else
		return (1);
}

int	byte_counter(t_core *core, int pc, t_opnum op)
{
	if (op < e_ldi)
		return (byte_counter1(core, pc, op));
	else
		return (byte_counter2(core, pc, op));
}
