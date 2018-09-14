/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:15:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 10:25:51 by zbatik           ###   ########.fr       */
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

int corrupted_encoding_byte(void)
{
    ft_putendl("corrupted parameter encoding byte");
    return (1);
}

void            modify_carry(t_process *cursor, t_opnum op)
{
    if ((index_opinfo(op)).modifies_carry)
        cursor->carry = !cursor->carry;
}

unsigned char	*ft_bytencpy(unsigned char *dst, const unsigned char *src, int len)
{
	int i;

	i = -1;
	while (++i < len)
		dst[i] = src[i];
	return (dst);
}

/*
**  cpy_from_reg
**  copy REG_SIZE (ie [4]) bytes from a reg to the active memory
*/

void    cpy_from_reg(t_core *core, t_byte *reg_entry, int cpy_from)
{
    unsigned char *dest;

    dest = core->mem + (cpy_from % MEM_SIZE);
    ft_bytencpy(dest, reg_entry, REG_SIZE);
}

void    write_to_reg(t_process *cursor, int reg_num, int input)
{
    int             rev;
    unsigned char   *reg;
    unsigned char   *input_conv;

    rev = rev_endian(input);
    input_conv = (unsigned char*)&rev;
    reg = (unsigned char*)cursor->reg[reg_num];
    ft_bytencpy(reg, input_conv, 4);
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