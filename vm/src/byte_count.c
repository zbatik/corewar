/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:12:43 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 13:24:18 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int or_gen(t_byte eb)
{
	if (eb == RRR)
		return (B_RRR);
	else if (eb == RIR)
		return (B_RIR);
	else if (eb == DIR)
		return (B_DIR);
	else if (eb == DRR)
		return (B_DRR);
	else
		return (1);
}

static int ldi_gen(t_byte en)
{
	if (eb == RRR)
		return (B_RRR);
	else if (eb == DRR)
		return (B_DRR);
	else if (eb == IRR)
		return (B_IRR);
	else if (eb == RDR)
		return (B_RDR);
	else if (eb == DRR)
		return (B_DRR);
	else if (eb == IDR)
		return (B_IDR);
	else
		return (1);
}

int byte_count(t_core *core, t_process *cursor, t_opnum op)
{
	t_byte eb;

	eb = MEM_VAL_PC_RELATIVE(1);
    if (op == e_live)
        return (5);
	else if (op == e_ld)
    {
		if (eb == DR)
			return (B_DR);
		else if (eb == IR)
			return (B_IR);
		else
			return (1)
    }
	else if (op == e_st)
	{
		if (eb == RI)
			return (B_RI);
		else if (eb == RR)
			return (B_RR);
		else
			return (1);
	}
	else if (op == e_add)
		return (B_RRR);
	else if (op == e_sub)
		return (B_RRR);
	else if (op == e_and)
		return (or_gen(eb));
	else if (op == e_or)
		return (or_gen(eb));
    else if (op == 	e_xor)
		return (or_gen(eb));
	else if (op == e_zjmp)
		return (3);
	else if (op == e_ldi)
		return (ldi_gen(en));
	else if (op == e_sti)
	else if (op == e_fork)
		return (3);
	else if (op == e_lld)
	else if (op == e_lldi)
		return (ldi_gen(en));
	else if (op == e_lfork)
		return (3);
	else if (op == e_aff)
		return (3);
}