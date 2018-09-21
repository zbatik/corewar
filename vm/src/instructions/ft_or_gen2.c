/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_gen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:41:53 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/21 22:12:27 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	op_rrr is correct
*/

static int op_rrr(t_core *core, t_process *cursor, int *param1, int *param2)
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

/*
**	op_rir is correct
*/

static int op_rir(t_core *core, t_process *cursor, int *param1, int *param2)
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

/*
**	op_rdr is correct
*/

static int op_rdr(t_core *core, t_process *cursor, int *param1, int *param2)
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

/*
**	op_dir is correct
*/

static int op_dir(t_core *core, t_process *cursor, int *param1, int *param2)
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

static int op_ddr(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int dir1;
	int dir2;
    
	dir1 = PC(2);
	dir2 = PC(6);
    *param1 = convert_bytes_to_int(core, dir1, 4);
	*param2 = convert_bytes_to_int(core, dir2, 4);
	if (core->pbp)
		ft_printf(1, na, "DDR: %x recieved dir1 %d dir2 %d\n", DDR, *param1, *param2);
	return (1);
}

static int op_drr(t_core *core, t_process *cursor, int *param1, int *param2)
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

static int op_idr(t_core *core, t_process *cursor, int *param1, int *param2)
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

static int op_iir(t_core *core, t_process *cursor, int *param1, int *param2)
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

static int op_irr(t_core *core, t_process *cursor, int *param1, int *param2)
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

int ft_op(t_core *core, t_process *cursor, int *param1, int *param2)
{
    int success;

    if (PARA_ENCODE_BYTE == RRR)
        success = op_rrr(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == RIR)
        success = op_rir(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == RDR)
        success = op_rdr(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == DIR)
        success = op_dir(core, cursor, param1, param2);
    else if (PARA_ENCODE_BYTE == DRR)
        success = op_drr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == DDR)
        success = op_ddr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IDR)
        success = op_idr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IRR)
        success = op_irr(core, cursor, param1, param2);
	else if (PARA_ENCODE_BYTE == IIR)
        success = op_iir(core, cursor, param1, param2);
    else
    {
        corrupted_encoding_byte();
        success = 0;
    }
    return (success);
}