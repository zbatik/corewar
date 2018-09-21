/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 12:12:43 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/21 20:51:29 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int or_gen(t_byte eb)
{
	if (eb == RRR)
		return (B_RRR);
	else if (eb == RIR)
		return (B_RIR);
	else if	(eb == RDR)
		return (B_RDR);
	else if (eb == IRR)
		return (B_IRR);
	else if (eb == IIR)
		return (B_IIR);
	else if (eb == IDR)
		return (B_IDR);
	else if (eb == DIR)
		return (B_DIR);
	else if (eb == DRR)
		return (B_DRR);
	else if (eb == DDR)
		return (B_DDR);
	else
		return (1);
}

static int ldi_gen(t_byte eb)
{
	if (eb == RRR)
		return (B_RRR);
	else if (eb == DRR)
		return (B_DRR - 2);
	else if (eb == IRR)
		return (B_IRR);
	else if (eb == RDR)
		return (B_RDR - 2);
	else if (eb == DDR)
		return (B_DDR - 4);
	else if (eb == IDR)
		return (B_IDR - 2);
	else
		return (1);
}

static int sti_gen(t_byte eb)
{
	if (eb == RRR)
		return (B_RRR);
	else if (eb == RDR)
		return (B_RDR - 2);
	else if (eb == RIR)
		return (B_RIR);
	else if (eb == RRD)
		return (B_RRD - 2);
	else if (eb == RDD)
		return (B_RDD - 4);
	else if (eb == RID)
		return (B_RID - 2);
	else
		return (1);
}

static int ld_gen(t_byte eb)
{
		if (eb == DR)
			return (B_DR);
		else if (eb == IR)
			return (B_IR);
		else
			return (1);
}

int byte_counter(t_core *core, int pc, t_opnum op)
{
	t_byte eb;

	eb = core->mem[pc + 1];
    if (op == e_live)
        return (5);
	else if (op == e_ld)
		return(ld_gen(eb));
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
		return (ldi_gen(eb));
	else if (op == e_sti)
		return (sti_gen(eb)); 		// change this: this is WRONG!!!
	else if (op == e_fork)
		return (3);
	else if (op == e_lld)
		return(ld_gen(eb));
	else if (op == e_lldi)
		return (ldi_gen(eb));
	else if (op == e_lfork)
		return (3);
	else if (op == e_aff)
		return (3);
	else
		return (1);
}