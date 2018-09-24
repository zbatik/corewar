/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:32:26 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/23 17:06:57 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_aff(t_core *core, t_process *cursor)
{
    int reg;
    int byte_count;

    byte_count = general_processing(core, cursor, e_aff);
    if (byte_count == 1)
        return (byte_count);
    if (PARA_ENCODE_BYTE != R)
        return(corrupted_encoding_byte(core));
    reg = CORE_VAL(2);
    if (!valid_reg(reg))
        return (1);
    ft_putchar(cursor->reg[reg - 1][REG_SIZE - 1]);
    return (byte_count);
}