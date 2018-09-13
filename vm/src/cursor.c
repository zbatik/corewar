/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:31:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/13 15:46:30 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void    process_add(t_process *cursor, int pc, int player_num, int ind)
{
    int i;
    int j;
    
    cursor->id = ind;
    cursor->pc = pc;
    cursor->carry = 0;
    write_to_reg(cursor, 0, player_num);
    i = 0;
    while (++i < REG_NUMBER)
    {
        j = -1;
        while (++j < REG_SIZE)
            cursor->reg[i][j] = 0;
    }
}