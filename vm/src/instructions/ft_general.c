/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:21:05 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/25 18:47:52 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void	modify_carry(t_core *core, t_process *cursor, int val)
{
	if (val == 0)
	{
		if (PBP && cursor->carry == 1)
			ft_putendl_cl("carry unchanged at 1", y);
		else if (PBP && cursor->carry == 0)
			ft_putendl_cl("carry flipped from 0 to 1", y);
		cursor->carry = 1;
	}
	else
	{
		if (PBP && cursor->carry == 0)
			ft_putendl_cl("carry unchanged at 0", y);
		else if (PBP && cursor->carry == 1)
			ft_putendl_cl("carry flipped from 1 to 0", y);
		cursor->carry = 0;
	}
}

int		get_indir(t_core *core, t_process *cursor, int start, t_opnum op)
{
	int indir;
	int indir_loc;
	int rel_index;
	int ind_val;

	indir_loc = PC(start);
	indir = convert_bytes_to_int(core, indir_loc, IND_SIZE);
	if (op == e_lld || op == e_lldi)
		rel_index = PC(indir);
	else
		rel_index = PC(indir % IDX_MOD);
	ind_val = convert_bytes_to_int(core, rel_index, IND_SIZE);
	if (PBP)
		ft_printf(1, na, "cacluated indir as %d, read from pc + %d\n",
		ind_val, rel_index);
	return (ind_val);
}

int		get_dir(t_core *core, t_process *cursor, int start, t_opnum op)
{
	int dir;
	int dir_val;

	dir = PC(start);
	if (index_opinfo(op).funky_dir_size)
		dir_val = convert_bytes_to_int(core, dir, IND_SIZE);
	else
		dir_val = convert_bytes_to_int(core, dir, DIR_SIZE);
	if (PBP)
		ft_printf(1, na, "calcuated dir as %d\n", dir_val);
	return (dir_val);
}

int		general_processing(t_core *core, t_process *cursor, t_opnum op)
{
	int byte_count;

	if (PBP)
		print_instr_info(core, cursor, op);
	byte_count = byte_counter(core, cursor->pc, op);
	if (PBP && byte_count == 1)
		corrupted_encoding_byte(core);
	return (byte_count);
}
