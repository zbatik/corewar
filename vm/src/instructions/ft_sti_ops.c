/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 09:46:28 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/25 16:04:32 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	sti_rrr(t_core *core, t_process *cursor, int *ind1, int *ind2)
{
	int reg1;
	int reg2;

	reg1 = CORE_VAL(3);
	reg2 = CORE_VAL(4);
	if (0 == convert_reg_to_int(cursor, reg1, ind1))
		return (0);
	if (0 == convert_reg_to_int(cursor, reg2, ind2))
		return (0);
	if (PBP)
		ft_printf(1, na,
		"RRR endcoding %x: r%d holding and %d and r%d holding %d\n",
		PARA_ENCODE_BYTE, reg1, *ind1, reg2, *ind2);
	return (1);
}

int	sti_rdr(t_core *core, t_process *cursor, int *ind1, int *ind2)
{
	int reg;

	reg = CORE_VAL(5);
	*ind1 = get_dir(core, cursor, 2, e_sti);
	if (0 == convert_reg_to_int(cursor, reg, ind2))
		return (0);
	if (PBP)
		ft_printf(1, na, "RDR endcoding %x: r%d holding %d\n",
		PARA_ENCODE_BYTE, reg, *ind2);
	return (1);
}

int	sti_rir(t_core *core, t_process *cursor, int *ind1, int *ind2)
{
	int reg;

	reg = CORE_VAL(5);
	*ind1 = get_indir(core, cursor, 2, e_sti);
	if (0 == convert_reg_to_int(cursor, reg, ind2))
		return (0);
	if (PBP)
		ft_printf(1, na,
		"RIR endcoding %x: r%d holding %d\n",
		PARA_ENCODE_BYTE, reg, *ind2);
	return (1);
}
