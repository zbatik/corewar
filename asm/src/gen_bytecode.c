/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:46:59 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/11 13:47:00 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	gen_bytecode(t_input *elem)
{
	char	code[elem->byte_count];
	int 	i;
	char	*tmp;
	t_opnum op;

	op = inst_to_enum((char*)elem->line);
	tmp = ft_itoa(op);
	code[0] = tmp[0];
	code[1] = tmp[1];
	i = 2;


}
