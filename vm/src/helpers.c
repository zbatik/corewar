/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:15:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/12 15:49:47 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_bool  valid_reg(int rX)
{
    if (rX >= 0x01 && rX <= 0x10)
        return (1);
    else
    {
        return (0);
        if (DEBUG)
            ft_putendl("corrupted register");
    }
}

/*
**  cpy_from_reg
**  copy REG_SIZE (ie [4]) bytes from a reg to the active memory
*/

void    cpy_from_reg(t_core *core, t_byte *reg_entry, int cpy_from)
{
    char *dest;

    dest = (char*)core->mem + (cpy_from % MEM_SIZE);
    ft_strncpy(dest, (char*)reg_entry, REG_SIZE);
}

/*
**  byte_to_int
**  take either an unsigned char[2] or unsigned char[4]
**  and convert it to an int
*/

int    byte_to_int(unsigned char *input, int len)
{
    return (input[len - 1]);
}