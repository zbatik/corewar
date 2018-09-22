/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 18:53:05 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 05:29:20 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int cpy_reg_to_reg(t_process *cursor, int dst, int src)
{
    int i;

    if ((!valid_reg(src)) || (!valid_reg(dst)))
        return (0);
	i = -1;
    while (++i < REG_SIZE)
    {
        cursor->reg[dst - 1][i] = cursor->reg[src - 1][i];
    }
    return (1);
}

int cpy_reg_to_mem(t_core *core, t_process *cursor, int reg, int start_ind)
{
	int i;
	int colour;

	if (!valid_reg(reg))
        return (0);
	colour = core->colouring[cursor->pc];
	i = -1;
	while (++i < REG_SIZE)
	{
		core->mem[(start_ind + i) % MEM_SIZE] = cursor->reg[reg - 1][i];
		core->colouring[(start_ind + i) % MEM_SIZE] = colour;
	}
	return (1);
}

int    cpy_straight_to_mem(t_core *core, t_byte *info, int start_ind)
{
	int i;

	i = -1;
	while (++i < REG_SIZE)
		core->mem[(start_ind + i) % MEM_SIZE] = info[i];
	return (1);
}

int    cpy_int_to_reg(t_process *cursor, int n, int reg)
{
	int		i;
	int		rev_n;
	t_byte	*byte_n;

	if (!valid_reg(reg))
        return (0);
	rev_n = rev_endian(n);
	byte_n = (t_byte*)&rev_n;
	i = -1;
	while (++i < REG_SIZE)
		cursor->reg[reg - 1][i] = byte_n[i];
	return (1);
}

int cpy_mem_to_reg(t_core *core, t_process *cursor, int reg, int start_ind)
{
	int i;

	if (!valid_reg(reg))
        return (0);
	i = -1;
	while (++i < REG_SIZE)
	{
		cursor->reg[reg - 1][i] = core->mem[(start_ind + i) % MEM_SIZE];
	}
	return (1);
}

