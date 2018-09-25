/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:14 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/25 16:34:01 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	sti_rid(t_core *core, t_process *cursor, int *ind1, int *ind2)
{
	*ind1 = get_indir(core, cursor, 3, e_sti);
	*ind2 = get_dir(core, cursor, 5, e_sti);
	if (PBP)
		ft_printf(1, na, "RID endcoding %x\n",
				PARA_ENCODE_BYTE);
	return (1);
}

static int	sti_rdd(t_core *core, t_process *cursor, int *ind1, int *ind2)
{
	*ind1 = get_dir(core, cursor, 3, e_sti);
	*ind2 = get_dir(core, cursor, 5, e_sti);
	if (PBP)
		ft_printf(1, na, "RDD endcoding %x\n",
				PARA_ENCODE_BYTE);
	return (1);
}

static int	sti_rrd(t_core *core, t_process *cursor, int *ind1, int *ind2)
{
	int reg;

	reg = CORE_VAL(3);
	if (0 == convert_reg_to_int(cursor, reg, ind1))
		return (0);
	*ind2 = get_dir(core, cursor, 4, e_sti);
	if (PBP)
		ft_printf(1, na, "RRD endcoding %x: r%d holding %d and dir %d\n",
				PARA_ENCODE_BYTE, CORE_VAL(2), *ind1, *ind2);
	return (1);
}

static int	sti_type(t_core *core, t_process *cursor, int *ind1, int *ind2)
{
	int success;

	if (PARA_ENCODE_BYTE == RRR)
		success = sti_rrr(core, cursor, ind1, ind2);
	else if (PARA_ENCODE_BYTE == RDR)
		success = sti_rdr(core, cursor, ind1, ind2);
	else if (PARA_ENCODE_BYTE == RIR)
		success = sti_rir(core, cursor, ind1, ind2);
	else if (PARA_ENCODE_BYTE == RRD)
		success = sti_rrd(core, cursor, ind1, ind2);
	else if (PARA_ENCODE_BYTE == RDD)
		success = sti_rdd(core, cursor, ind1, ind2);
	else if (PARA_ENCODE_BYTE == RID)
		success = sti_rid(core, cursor, ind1, ind2);
	else
		return (0);
	return (success);
}

int			ft_sti(t_core *core, t_process *cursor)
{
	int byte_count;
	int reg;
	int ind1;
	int ind2;
	int ind;

	byte_count = general_processing(core, cursor, e_sti);
	if (byte_count == 1)
		return (1);
	reg = CORE_VAL(2);
	if (0 == sti_type(core, cursor, &ind1, &ind2))
		return (1);
	ind = PC((ind1 + ind2) % IDX_MOD) % MEM_SIZE;
	cpy_reg_to_mem(core, cursor, reg, ind);
	if (PBP)
		ft_printf(1, na, "contents of r%d copied to index %d\n", reg, ind);
	return (byte_count);
}
