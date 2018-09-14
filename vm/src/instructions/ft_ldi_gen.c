/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi_gen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:46:56 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/14 15:19:45 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	ft_ldi_gen(t_core *core, t_process *cursor, t_opnum op)
{
	general_processing(core, cursor, op);
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