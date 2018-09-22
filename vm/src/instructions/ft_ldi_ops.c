/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 06:13:18 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 06:46:19 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ld_rdr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int reg;
    int dir;

    reg = CORE_VAL(2);
    dir = PC(3);
    if (0 == convert_reg_to_int(cursor, reg, param1))
        return (0);
    *param2 = convert_bytes_to_int(core, dir, 2);
	if (core->pbp)
		ft_printf(1, na, "RDR: %x recieved r%d and dir of %d\n", RDR, reg, *param2);
    return (1);
}

int ld_ddr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int dir1;
	int dir2;
    
	dir1 = PC(2);
	dir2 = PC(4);
    *param1 = convert_bytes_to_int(core, dir1, 2);
	*param2 = convert_bytes_to_int(core, dir2, 2);
	if (core->pbp)
		ft_printf(1, na, "DDR: %x recieved dir1 %d dir2 %d\n", DDR, *param1, *param2);
	return (1);
}

int ld_drr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int dir;
	int reg;
    
	dir = PC(2);
	reg = CORE_VAL(4);
    *param1 = convert_bytes_to_int(core, dir, 2);
	if (0 == convert_reg_to_int(cursor, reg, param2))
        return (0);
	if (core->pbp)
		ft_printf(1, na, "DRR: %x recieved dir %d and r%d\n", DRR, *param1, reg);
	return (1);
}

int ld_idr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int dir;
	int read_from;
	int indir;
    
	indir = PC(2);
	dir = PC(4);
	read_from = PC(convert_bytes_to_int(core, indir, 2) % IDX_MOD);
    *param1 = convert_bytes_to_int(core, read_from, 4);
	*param2 = convert_bytes_to_int(core, dir, 2);
	if (core->pbp)
		ft_printf(1, na, "IDR: %x recieved indir %d and dir %d\n", IDR, read_from, *param2);
    return (1);
}
