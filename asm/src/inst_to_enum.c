/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_to_enum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 11:14:51 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/05 13:42:41 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_opnum inst_to_enum(char *str)
{
    while (ft_isws(*str))
        str++;
    if (ft_strnequ(str, "live", 5))
        return (e_live);
    else if (ft_strnequ(str, "lldi", 4))
        return (e_lldi);
    else if (ft_strnequ(str, "lld", 3))
        return (e_lld);
    else if (ft_strnequ(str, "ldi", 3))
        return (e_ldi);
    else if (ft_strnequ(str, "ld", 2))
        return (e_ld);
    else if (ft_strnequ(str, "sti", 3))
        return (e_sti);
    else if (ft_strnequ(str, "st", 2))
        return (e_st);
    else if (ft_strnequ(str, "add", 3))
        return (e_add);
    else if (ft_strnequ(str, "sub", 3))
        return (e_sub);
    else if (ft_strnequ(str, "and", 3))
        return (e_and);
    else if (ft_strnequ(str, "or", 2))
        return (e_or);
    else if (ft_strnequ(str, "xor", 3))
        return (e_xor);
    else if (ft_strnequ(str, "zjmp", 4))
        return (e_zjmp);
    else if (ft_strnequ(str, "fork", 4))
        return (e_fork);
    else if (ft_strnequ(str, "lfork", 5))
        return (e_lfork);
    else if (ft_strnequ(str, "aff", 3))
        return (e_aff);
    else
        return (null)
}