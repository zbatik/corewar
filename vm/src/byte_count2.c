/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_count2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 12:55:22 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/25 18:42:02 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int	bytes_or_gen(t_byte eb)
{
	if (eb == RRR)
		return (B_RRR);
	else if (eb == RIR)
		return (B_RIR);
	else if (eb == RDR)
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

int	bytes_ldi_gen(t_byte eb)
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

int	bytes_sti(t_byte eb)
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

int	bytes_ld_gen(t_byte eb)
{
	if (eb == DR)
		return (B_DR);
	else if (eb == IR)
		return (B_IR);
	else
		return (1);
}

int	bytes_st(t_byte eb)
{
	if (eb == RI)
		return (B_RI);
	else if (eb == RR)
		return (B_RR);
	else
		return (1);
}
