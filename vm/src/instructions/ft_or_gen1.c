/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_or_gen1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 14:25:14 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/22 01:55:36 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_or(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_or));
}

int ft_xor(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_xor));
}

int ft_and(t_core *core, t_process *cursor)
{
	return(ft_or_gen(core, cursor, e_and));
}