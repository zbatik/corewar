/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general_ops2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 01:43:04 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 01:55:50 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int op_drr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int dir;
	int reg;
    
	dir = PC(2);
	reg = CORE_VAL(6);
    *param1 = convert_bytes_to_int(core, dir, 4);
	if (0 == convert_reg_to_int(cursor, reg, param2))
        return (0);
	if (core->pbp)
		ft_printf(1, na, "DRR: %x recieved dir %d and r%d\n", DRR, *param1, reg);
	return (1);
}

int op_idr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int dir;
	int read_from;
	int indir;
    
	indir = PC(2);
	dir = PC(4);
	read_from = PC(convert_bytes_to_int(core, indir, 2) % IDX_MOD);
    *param1 = convert_bytes_to_int(core, read_from, 4);
	*param2 = convert_bytes_to_int(core, dir, 4);
	if (core->pbp)
		ft_printf(1, na, "IDR: %x recieved indir %d and dir %d\n", IDR, read_from, *param2);
    return (1);
}

int op_iir(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int indir1;
	int indir2;
	int read_from1;
	int read_from2;
    
	indir1 = PC(2);
	indir2 = PC(4);
	read_from1 = PC(convert_bytes_to_int(core, indir1, 2) % IDX_MOD);
	read_from2 = PC(convert_bytes_to_int(core, indir2, 2) % IDX_MOD);
    *param1 = convert_bytes_to_int(core, read_from1, 4);
	*param2 = convert_bytes_to_int(core, read_from2, 4);
	if (core->pbp)
		ft_printf(1, na, "IIR: %x recieved indir pos %d and indir pos %d\n", IIR, read_from1, read_from2);
    return (1);
}

int op_irr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int reg;
    int indir;
    int read_from;

 	indir = PC(2);
    reg = CORE_VAL(4);
	read_from = PC((convert_bytes_to_int(core, indir, 2) % IDX_MOD));
    *param1 = convert_bytes_to_int(core, read_from, 4);
    if (0 == convert_reg_to_int(cursor, reg, param2))
        return (0);
	if (core->pbp)
		ft_printf(1, na, "IRR: %x recieved indir pos %d of and r%d\n", IRR, read_from, reg);
    return (1);
}
