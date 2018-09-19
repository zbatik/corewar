/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:46:56 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/18 16:02:35 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	ft_ldi_gen(t_core *core, t_process *cursor, t_opnum op)
{
	int byte_count;
	byte_count = general_processing(core, cursor, op);
	if (byte_count == 1)
        return (byte_count);
	return (3);
}

int ft_ldi(t_core *core, t_process *cursor)
{
	return(ft_ldi_gen(core, cursor, e_ldi));
}

int ft_lldi(t_core *core, t_process *cursor)
{
	return(ft_ldi_gen(core, cursor, e_lldi));
}