/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:31:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/10 16:53:08 by zbatik           ###   ########.fr       */
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
    ft_strncpy((char*)cursor->reg[0], (char*)&player_num, REG_SIZE);
    i = 0;
    while (++i < REG_NUMBER)
    {
        j = -1;
        while (++j < REG_SIZE)
            cursor->reg[i][j] = 0;
    }
}