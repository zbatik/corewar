/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 14:37:13 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/03 15:44:47 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	live(t_byte *reg, int pc)
{
	char	name[5];
	int		i;

	i = -1;
	while (++i < 4)
		name[i] = reg[pc + 1 + i % MEM_SIZE];
	name[i] = 0;
	ft_putstr_cl("Player ", g);
	ft_putstr_cl(name, g);
	ft_putendl_cl(" is alive", g);
	return (5);
}

void		execute(t_byte *reg, int pc)
{
	switch (*reg)
	{
		case e_live :
			live(reg, pc);
			break;
		case e_ld :
			break;
		case e_st :
			break;
		case e_add :
			break;
		case e_sub :
			break;
		case e_and :
			break;
		case e_or :
			break;
		case e_xor :
			break;
		case e_zjmp :
			break;
		case e_ldi :
			break;
		case e_sti :
			break;
		case e_fork :
			break;
		case e_lld :
			break;
		case e_lldi :
			break;
		case e_lfork :
			break;
		case e_aff :
			break;
		case e_null :
			ft_putendl("Not real command");
	}

}
