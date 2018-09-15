/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:32:02 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 13:36:32 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_fork(t_core *core, t_process *cursor)
{
	int jump;

    general_processing(core, cursor, e_fork);
	jump = (byte_to_int(MEM_PNT_PC_RELATIVE(1) ,2) % IDX_MOD) % MEM_SIZE;
	duplicate_process(core, cursor, jump);
	return (3);
}