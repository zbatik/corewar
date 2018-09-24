/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:58:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 16:13:24 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	ft_ld_gen(t_core *core, t_process *cursor, t_opnum op)
{
	int byte_count;
	int load_val;
	int reg;

	byte_count = general_processing(core, cursor, op);
	if (byte_count == 1)
		return (byte_count);
	if (DR == PARA_ENCODE_BYTE)
	{
		load_val = get_dir(core, cursor, 2, op);
		reg = CORE_VAL(6);
	}
	else if (IR == PARA_ENCODE_BYTE)
	{
		load_val = get_indir(core, cursor, 2, op);
		reg = CORE_VAL(4);
	}
	else
		return (corrupted_encoding_byte(core));
	modify_carry(core, cursor, load_val);
	if (0 == cpy_int_to_reg(cursor, load_val, reg))
		return (1);
	return (byte_count);
}

int			ft_ld(t_core *core, t_process *cursor)
{
	return (ft_ld_gen(core, cursor, e_ld));
}

int			ft_lld(t_core *core, t_process *cursor)
{
	return (ft_ld_gen(core, cursor, e_lld));
}
