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
#include <stdio.h>

void	op_code_char(char	*code, t_opnum op)
{
	if (op < 16)
	{
		code[0] = '0';
		code[1] = ft_itoa_base(op, 16)[0];
	}
	else
		ft_strcpy(code, "10");
}

void	gen_bytecode(t_input *elem)
{
	char	code[elem->byte_count];
	//int 	i;
	//char	*tmp;
	t_opnum op;

	op = inst_to_enum((char*)elem->line);
	//tmp = ft_itoa(op);
	op_code_char((char *)code, op);
	code[3] = '\0';
	elem->byte_code = (unsigned char *) ft_strdup(code);
	printf("Current byte code: %s\n",elem->byte_code);
	printf("Param encoding: %d\n\n",elem->param_encoding);
}
