/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:31:24 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 16:02:33 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_lfork(t_core *core, t_process *cursor)
{    
	int jump;
	int byte_count;

    byte_count = general_processing(core, cursor, e_lfork);
	if (byte_count == 1)
        return (byte_count);
	jump = (byte_to_int(MEM_PNT_PC_RELATIVE(1) ,2)) % MEM_SIZE;
	duplicate_process(core, cursor, jump);
	return (byte_count);
}