/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:33:14 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/19 16:25:08 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

int ft_sti(t_core *core, t_process *cursor)
{
    int byte_count;

    byte_count = general_processing(core, cursor, e_sti);
    return (byte_count);
}