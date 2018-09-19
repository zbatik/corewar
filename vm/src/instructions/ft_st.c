/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 17:59:54 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 16:02:43 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_st(t_core *core, t_process *cursor)
{
    int r_cpy_from;
    int r_cpy_to;

    general_processing(core, cursor, e_st);
    r_cpy_from = core->mem[cursor->pc + 2];
    if (!valid_reg(r_cpy_from))
        return (1);
    if (RR == PARA_ENCODE_BYTE)
    {
        r_cpy_to = core->mem[cursor->pc + 3];
        if (!valid_reg(r_cpy_to))
            return (1);
        ft_bytencpy(cursor->reg[r_cpy_from], cursor->reg[r_cpy_to], 4);
        return (4);
    }
    else if (RI == PARA_ENCODE_BYTE)
    {
        cpy_from_reg(core, cursor->reg[r_cpy_from], 
            cursor->pc + byte_to_int(core->mem, 2));
        return (5);
    }
    else
        return (corrupted_encoding_byte());
    return (5);
}