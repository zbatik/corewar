/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:59:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/25 15:37:37 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int	ft_st(t_core *core, t_process *cursor)
{
	int ind;
	int byte_count;
	int reg;

	reg = CORE_VAL(2);
	byte_count = general_processing(core, cursor, e_st);
	if (byte_count == 1)
		return (1);
	if (RR == PARA_ENCODE_BYTE)
	{
		if (0 == convert_reg_to_int(cursor, CORE_VAL(3), &ind))
			return (1);
	}
	else if (RI == PARA_ENCODE_BYTE)
		ind = get_indir(core, cursor, 3, e_st);
	else
		return (corrupted_encoding_byte(core));
	cpy_reg_to_mem(core, cursor, reg, ind);
	return (byte_count);
}
