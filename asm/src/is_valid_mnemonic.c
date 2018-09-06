/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_mnemonic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:47:33 by emaune            #+#    #+#             */
/*   Updated: 2018/09/06 15:04:56 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				is_valid_mnemonic(char *str)
{
	if (ft_strequ(str, "live") || ft_strequ(str, "lldi")
			|| ft_strequ(str, "lld") || ft_strequ(str, "ldi")
			|| ft_strequ(str, "sti") || ft_strequ(str, "st")
			|| ft_strequ(str, "add") || ft_strequ(str, "sub")
			|| ft_strequ(str, "and") || ft_strequ(str, "or")
			|| ft_strequ(str, "xor") || ft_strequ(str, "zjmp")
			|| ft_strequ(str, "fork") || ft_strequ(str, "lfork")
			|| ft_strequ(str, "aff") || ft_strequ(str, "ld"))
		return (1);
	return (0);
}
