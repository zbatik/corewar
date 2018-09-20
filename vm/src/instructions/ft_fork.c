/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:32:02 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/20 12:08:29 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_fork(t_core *core, t_process *cursor)
{
	int jump;
	int	byte_count;

    byte_count = general_processing(core, cursor, e_fork);
    if (byte_count == 1)
        return (byte_count);
	jump = convert_2b_to_int(core, cursor->pc + 1) % IDX_MOD;
	//jump = (byte_to_int(MEM_PNT_PC_RELATIVE(1) ,2) % IDX_MOD) % MEM_SIZE;
	duplicate_process(core, cursor, jump);
	return (byte_count);
} 