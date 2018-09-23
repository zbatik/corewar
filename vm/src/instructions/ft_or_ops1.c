/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 01:38:26 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/23 17:09:45 by zbatik           ###   ########.fr       */
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
	if (core->pbp)
		ft_printf(1, na, "RRR: %x recieved r%d and r%d\n", RRR, reg1, reg2);
    return (1);
}

int op_rir(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int reg;
    int indir;
    int read_from;

    reg = CORE_VAL(2);
    indir = PC(3);
    if (0 == convert_reg_to_int(cursor, reg, param1))
        return (0);
    read_from = PC(convert_bytes_to_int(core, indir, 2) % IDX_MOD);
    *param2 = convert_bytes_to_int(core, read_from, 4);
	if (core->pbp)
		ft_printf(1, na, "RIR: %x recieved r%d and indir at pos %d\n", RIR, reg, read_from);
    return (1);
}

int op_rdr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int reg;
    int dir;

    reg = CORE_VAL(2);
    dir = PC(3);
    if (0 == convert_reg_to_int(cursor, reg, param1))
        return (0);
    *param2 = convert_bytes_to_int(core, dir, 4);
	if (core->pbp)
		ft_printf(1, na, "RDR: %x recieved r%d and dir of %d\n", RDR, reg, *param2);
    return (1);
}

int op_dir(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int dir;
	int read_from;
	int indir;
    
	dir = PC(2);
	indir = PC(6);
    *param1 = convert_bytes_to_int(core, dir, 4);
	read_from = PC(convert_bytes_to_int(core, indir, 2) % IDX_MOD);
    *param2 = convert_bytes_to_int(core, read_from, 4);
	if (core->pbp)
		ft_printf(1, na, "DIR: %x recieved dir %d and indir %d\n", DIR, *param1, read_from);
    return (1);
}

int op_ddr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int dir1;
	int dir2;
    
	dir1 = PC(2);
	dir2 = PC(6);
    *param1 = convert_bytes_to_int(core, dir1, 4);
	*param2 = convert_bytes_to_int(core, dir2, 4);
	if (PBP)
		ft_printf(1, na, "DDR: %x recieved dir1 %d dir2 %d\n", DDR, *param1, *param2);
	return (1);
}