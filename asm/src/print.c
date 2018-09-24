/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:09:34 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/24 16:09:35 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		get_size(char arg)
{
	if (arg == 'I')
		return (IND_SIZE);
	else if (arg == 'D')
		return (DIR_SIZE);
	else if (arg == 'd')
		return (ASM_DIR);
	else
		return (ASM_REG);
	return (0);
}
