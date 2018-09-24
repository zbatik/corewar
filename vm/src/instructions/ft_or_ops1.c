/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 01:38:26 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 14:28:16 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int op_rrr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int reg1;
    int reg2;

    reg1 = CORE_VAL(2);
    reg2 = CORE_VAL(3);
    if (0 == convert_reg_to_int(cursor, reg1, param1))
        return (0);
    if (0 == convert_reg_to_int(cursor, reg2, param2))
        return (0);
	if (PBP)
		ft_printf(1, na, "RRR: %x recieved r%d and r%d\n", RRR, reg1, reg2);
    return (1);
}

int op_rir(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int     reg;
    t_opnum op;

    op = PC(0);
    reg = CORE_VAL(2);
    if (0 == convert_reg_to_int(cursor, reg, param1))
        return (0);
    *param2 = get_indir(core, cursor, 3, op);
	//if (core->pbp)
	//	ft_printf(1, na, "RIR: %x recieved r%d and indir at pos %d\n", RIR, reg, read_from);
    return (1);
}

int op_rdr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int     reg;
    t_opnum op;

    op = PC(0);
    reg = CORE_VAL(2);
    if (0 == convert_reg_to_int(cursor, reg, param1))
        return (0);
    *param2 = get_dir(core, cursor, 3, op);
//	if (core->pbp)
//		ft_printf(1, na, "RDR: %x recieved r%d and dir of %d\n", RDR, reg, *param2);
    return (1);
}

int op_dir(t_core *core, t_process *cursor, int *param1, int *param2)
{
    t_opnum op;
    
	op = PC(0);
	*param1 = get_dir(core, cursor, 2, op);
	*param2 = get_indir(core, cursor, 6, op);
//	if (core->pbp)
//		ft_printf(1, na, "DIR: %x recieved dir %d and indir %d\n", DIR, *param1, read_from);
    return (1);
}

int op_ddr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    t_opnum op;

	op = PC(0);
    *param1 = get_dir(core, cursor, 2, op);
	*param2 = get_dir(core, cursor, 6, op);
	if (PBP)
		ft_printf(1, na, "DDR: %x recieved dir1 %d dir2 %d\n", DDR, *param1, *param2);
	return (1);
}