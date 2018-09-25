/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 17:15:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/24 15:52:45 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_bool	valid_reg(int reg)
{
	if (reg >= 0x01 && reg <= 0x10)
		return (1);
	else
	{
		ft_putendl_cl("corrupted register", lr);
		return (0);
	}
}

int		corrupted_encoding_byte(t_core *core)
{
	if (PBP)
		ft_putendl_cl("corrupted parameter encoding byte", lr);
	return (1);
}

t_byte	*ft_bytencpy(t_byte *dst, const t_byte *src, int len)
{
	int i;

	i = -1;
	while (++i < len)
		dst[i] = src[i];
	return (dst);
}

int		convert_reg_to_int(t_process *cursor, int reg, int *output)
{
	if (!valid_reg(reg))
		return (0);
	*output = rev_endian(*(int*)cursor->reg[reg - 1]);
	return (1);
}

int		convert_bytes_to_int(t_core *core, int start, int len)
{
	t_byte	int_bytes[4];
	int		ind;
	int		i;
	int		ret;

	ft_bzero(int_bytes, 4);
	i = len - 1;
	while (i >= 0)
	{
	 	ind = (start + len - 1 - i) % MEM_SIZE;
		ind = (ind < 0 ? MEM_SIZE + ind : ind);
		int_bytes[i] = core->mem[ind];
		i--;
	}
	ret = *(int*)int_bytes;
	if (ret > 32768) // make these number varibale
		ret -= 65536;
	return (ret);
}
