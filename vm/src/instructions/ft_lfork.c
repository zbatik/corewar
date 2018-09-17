/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:31:24 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 13:36:12 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_lfork(t_core *core, t_process *cursor)
{    
	int jump;

    general_processing(core, cursor, e_lfork);
	jump = (byte_to_int(MEM_PNT_PC_RELATIVE(1) ,2)) % MEM_SIZE;
	duplicate_process(core, cursor, jump);
	return (3);
}