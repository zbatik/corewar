/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:32:26 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 10:29:40 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_aff(t_core *core, t_process *cursor)
{
    int r1;
    general_processing(core, cursor, e_aff);
    r1 = core->mem[cursor->pc + 2];
    if (core->mem[cursor->pc + 1] == 0x40)
        return (corrupted_encoding_byte());
    if (!valid_reg(r1))
        return (1);
    ft_putchar((char)cursor->reg[r1][REG_SIZE - 1]);
    ft_putchar('\n');
    return (3);
}