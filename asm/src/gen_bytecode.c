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
	int 	i;
	char	*tmp;
	char	**split;
	int		inter;
	t_opnum op;

	op = inst_to_enum((char*)elem->line);
	i = 0;
	op_code_char((char *)code, op);
	elem->byte_code = (unsigned char *) ft_strdup(code);
	tmp = (char *)elem->line;
    while(ft_isws(*tmp) == FALSE && *tmp != '\0')
        tmp++;
    while(ft_isws(*tmp) == TRUE && *tmp != '\0')
        tmp++;
    split = ft_strsplit(tmp, ',');
	while (elem->args[i] != '\0')
	{
		if (elem->args[i] == 'D')
		{
			//Direct parsing

		}
		else if (elem->args[i] == 'I')
		{
			//indirect parsing, check if its a label.
			if (split[i][1] == ':')
			{
				printf("Arg label\n");
			}
			else
			{
				inter = ft_atoi(split[i] + 1);
				swapnfree((char **)&elem->byte_code, ft_strjoin((char *)elem->byte_code, ft_itoa_base(inter, 16)));
			}
			// if it is a label index it properly;
		}
		else
		{
			//register parsing
		}
		i++;
	}
	
	printf("Current byte code: %s\n",elem->byte_code);
	printf("Param encoding: %d\n\n",elem->param_encoding);
}
