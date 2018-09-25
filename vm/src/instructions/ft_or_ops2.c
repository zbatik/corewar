/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_ops2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 01:43:04 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 14:28:22 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int op_drr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int		reg;
	t_opnum	op;
	
	op = PC(0);
	reg = CORE_VAL(6);
    *param1 = get_dir(core, cursor, 2, op);
	if (0 == convert_reg_to_int(cursor, reg, param2))
        return (0);
	//if (core->pbp)
	//	ft_printf(1, na, "DRR: %x recieved dir %d and r%d\n", DRR, *param1, reg);
	return (1);
}

int op_idr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	t_opnum	op;
	
	op = PC(0);
    *param1 = get_indir(core, cursor, 2, op);
	*param2 = get_dir(core, cursor, 4, op);
//	if (core->pbp)
//		ft_printf(1, na, "IDR: %x recieved indir %d and dir %d\n", IDR, read_from, *param2);
    return (1);
}

int op_iir(t_core *core, t_process *cursor, int *param1, int *param2)
{
	t_opnum	op;
	
	op = PC(0);
    *param1 = get_indir(core, cursor, 2, op);
	*param2 = get_indir(core, cursor, 4, op);
//	if (core->pbp)
//		ft_printf(1, na, "IIR: %x recieved indir pos %d and indir pos %d\n", IIR, read_from1, read_from2);
    return (1);
}

int op_irr(t_core *core, t_process *cursor, int *param1, int *param2)
{
	int		reg;
	t_opnum	op;
	
	op = PC(0);
    reg = CORE_VAL(4);
    *param1 = get_indir(core, cursor, 2, op);
    if (0 == convert_reg_to_int(cursor, reg, param2))
        return (0);
//	if (core->pbp)
//		ft_printf(1, na, "IRR: %x recieved indir pos %d of and r%d\n", IRR, read_from, reg);
    return (1);
}
