/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_general.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:21:05 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 10:27:13 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

void general_processing(t_core *core, t_process *cursor, t_opnum op)
{
    if (DEBUG)
        print_instr_info(core, op, cursor->pc);
    modify_carry(cursor, op);
}