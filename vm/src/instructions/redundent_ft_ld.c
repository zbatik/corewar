/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:59:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 14:17:38 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_ld(t_core *core, t_process *cursor)
{
	ft_ld_gen(core, cursor, e_ld);
}

/*
int ft_ld(t_core *core, t_process *cursor)
{
    int rX;
    int param_add_byte;
    int ld_val;

    general_processing(core, cursor, e_ld);
    if (DR == PARA_ENCODE_BYTE)
        param_add_byte = 2;
    else if (IR == PARA_ENCODE_BYTE)
        param_add_byte = 0;
    else
        return (corrupted_encoding_byte());
	ld_val = byte_to_int(MEM_PNT_PC_RELATIVE(2), 2 + param_add_byte);
    rX = MEM_VAL_PC_RELATIVE(4 + param_add_byte);
    if (!valid_reg(rX))
        return (1);
    write_to_reg(cursor, rX, ld_val);
    return (5 + param_add_byte);
}*/