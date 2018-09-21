/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:32:26 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/21 22:46:13 by zbatik           ###   ########.fr       */
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
    reg = CORE_VAL(2);
    if (!valid_reg(reg))
        return (1);
    ft_putchar((char)cursor->reg[reg][REG_SIZE - 1]);
    ft_putchar('\n');
    return (byte_count);
}