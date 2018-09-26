/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 06:13:18 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/25 18:09:04 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	ldi_rdr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int reg;
	int op;

	op = CORE_VAL(0);
	reg = CORE_VAL(2);
	if (0 == convert_reg_to_int(cursor, reg, param1))
		return (0);
	*param2 = get_dir(core, cursor, 3, op);
	if (PBP)
		ft_printf(1, na, "RDR: %x recieved r%d with val %d\n",
		RDR, reg, *param1);
	return (1);
}

int	ldi_ddr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int op;

	op = CORE_VAL(0);
	*param1 = get_dir(core, cursor, 2, op);
	*param2 = get_dir(core, cursor, 4, op);
	if (PBP)
		ft_printf(1, na, "DDR: %x\n", DDR);
	return (1);
}

int	ldi_drr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int reg;
	int op;

	op = CORE_VAL(0);
	reg = CORE_VAL(4);
	*param1 = get_dir(core, cursor, 2, op);
	if (0 == convert_reg_to_int(cursor, reg, param2))
		return (0);
	if (PBP)
		ft_printf(1, na, "DRR: %x recieved r%d with val %d\n",
		RDR, reg, *param2);
	return (1);
}

int	ldi_idr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int op;

	op = CORE_VAL(0);
	*param1 = get_indir(core, cursor, 2, op);
	*param2 = get_dir(core, cursor, 4, op);
	if (PBP)
		ft_printf(1, na, "IDR: %x\n", IDR);
	return (1);
}

int	ldi_irr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int reg;
	int op;

	op = CORE_VAL(0);
	*param1 = get_indir(core, cursor, 2, op);
	reg = CORE_VAL(4);
	if (0 == convert_reg_to_int(cursor, reg, param2))
		return (0);
	if (PBP)
		ft_printf(1, na, "IRR: %x\n", IRR);
	return (1);
}
