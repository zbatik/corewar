/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:15:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/21 16:56:28 by zbatik           ###   ########.fr       */
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
		if (DEBUG)     // fix this
			ft_putendl("corrupted register");
	}
}

int corrupted_encoding_byte(void)
{
	ft_putendl("corrupted parameter encoding byte");
	return (1);
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

/*

*/
/*
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
*/
/*
**  byte_to_int
**  take either an unsigned char[2] or unsigned char[4]
**  and convert it to an int
*/

int    byte_to_int(unsigned char *input, int len)
{
	int             ret;
	unsigned char   store[4];

	ft_bytencpy(store, input, 4);
	if (len == 2)
	{
		store[2] = 0;
		store[3] = 0;
	}
	ret = *(int*)store;
	return (ret);
}

/*
** convert_reg_to_int
** correct 
*/

int convert_reg_to_int(t_process *cursor, int reg, int *output)
{
	if (!valid_reg(reg))
		return (0);
	*output = rev_endian(*(int*)cursor->reg[reg - 1]);
	return (1);
}

int convert_bytes_to_int(t_core *core, int start, int len)
{
	t_byte	int_bytes[4];
	int		i;
	int		j;
	int		ind;
	int		ret;

	ft_bzero(int_bytes, 4);
	i = 0;
	j = len;
	while (i < len)
	{
		ind = (start + j) % MEM_SIZE;
		ind = (ind < 0 ? MEM_SIZE + ind : ind);
		int_bytes[i] = core->mem[(start + j--) % MEM_SIZE];
		j--;
		i++;
	}
	ret = *(int*)int_bytes;
	if (ret > 32768) // make these number varibale
		ret -= 65536;
	return (ret);
}

int convert_2b_to_int(t_core *core, int start)
{
	t_byte	jump_bytes[4];
	int		i;
	int		jump;

	start = start - 2;
	if (start < 0)
		start = start + MEM_SIZE;
	i = -1;
	while (++i < 4)
		jump_bytes[i] = core->mem[(start + i) % MEM_SIZE];
	jump_bytes[0] = 0;
	jump_bytes[1] = 0;
	jump = rev_endian(*(int*)jump_bytes);
	if (jump > 32768)
		jump -= 65536;
	return (jump);
}