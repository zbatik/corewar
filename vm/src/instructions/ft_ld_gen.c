/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:58:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 01:25:50 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

/*
**	applies to both ld and lld
*/

static int ld_dr(t_core *core, t_process *cursor, int *reg)
{
	int val;
	int dir;

	dir = PC(2);
	*reg = CORE_VAL(6);
	val = convert_bytes_to_int(core, dir, 4);
	if (PBP)
		ft_printf(1, na, "DR: %x: load dir %d in r%d\n", IR, val, *reg);
	return (val);
}

static int ld_ir(t_core *core, t_process *cursor, int *reg, t_opnum op)
{
	int val;
	int load_from;
	int indir;

	indir = PC(2);
	*reg = CORE_VAL(4);
	if (op == e_ld)
		load_from = PC(convert_bytes_to_int(core, indir, 2) % IDX_MOD);
	else
		load_from = PC(convert_bytes_to_int(core, indir, 2));
	val = convert_bytes_to_int(core, load_from, 4);
	if (PBP)
		ft_printf(1, na, "IR: %x: load indir %x, from %d to r%d\n", IR, val, load_from, *reg);
	return (val);
}

static int ft_ld_gen(t_core *core, t_process *cursor, t_opnum op)
{
    int byte_count;
	int load_val;
	int reg;

    byte_count = general_processing(core, cursor, op);
    if (byte_count == 1)
        return (byte_count);
	if (DR == PARA_ENCODE_BYTE)
		load_val = ld_dr(core, cursor, &reg);
    else if (IR == PARA_ENCODE_BYTE)
		load_val = ld_ir(core, cursor, &reg, op);
	else
		return(corrupted_encoding_byte());
	modify_carry(core, cursor, load_val);
	if (0 == cpy_int_to_reg(cursor, load_val, reg))
		return (1);
    return (byte_count);
}

int ft_ld(t_core *core, t_process *cursor)
{
	return(ft_ld_gen(core, cursor, e_ld));
}

int ft_lld(t_core *core, t_process *cursor)
{
	return(ft_ld_gen(core, cursor, e_lld));
}
