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

char	*padded_itoa(int final_size, int to_convert)
{
	char	*ret;
	char	*tmp;
	int		i;

	ret = ft_strnew(final_size * 2 + 1);
	tmp = ft_itoa_base(to_convert, 16);
	i = 0;
	while (i - ft_strlen(tmp) > 0)
	{
		ret[i] = '0';
		ret[i + 1] = '0';
		//ft_strcpy(ret + i, "00");
		i ++;
	}
	swapnfree(&ret, ft_strjoin(ret, tmp));
	free(tmp);
	return (ret);

}

int	convert_to_byte(int num, int size, t_byte *code, int index)
{
	int	count;
	int	tmp;

	tmp = num;
	while (tmp > 0)
	{
		tmp /= 16;
		count++;
	}
	while(count > 0)
	{
		code[index++] = num - ft_pow(16, count);
		num -= ft_pow(16, count--);
	}
	return (index);
}

//*(t_byte*)&inter = ft_atoi(split[i]);
void	gen_bytecode(t_input *ahead, t_input *elem, int curr_byte_count)
{
	int 	i;
	char	*tmp;
	char	**split;
	int		inter;
	int		index;
	t_opnum op;
	//t_input	*label;

	op = inst_to_enum((char*)elem->line);
	i = 0;
	elem->byte_code = (t_byte *)malloc(sizeof(t_byte) * elem->byte_count);
	printf("Op translated: %d\n",(unsigned char) (index_opinfo(op)).op_number);
	elem->byte_code[0] = (unsigned char) (index_opinfo(op)).op_number;
	tmp = (char *)elem->line;
	(void) curr_byte_count;
	(void) ahead;
    while(ft_isws(*tmp) == FALSE && *tmp != '\0')
        tmp++;
    while(ft_isws(*tmp) == TRUE && *tmp != '\0')
        tmp++;
    split = ft_strsplit(tmp, ',');
    index  = 1;
	while (elem->args[i] != '\0')
	{
		if (elem->args[i] == 'D')
		{
			//direct parsing
			inter = ft_atoi(split[i]);
			index = convert_to_byte(inter, DIR_SIZE, elem->byte_code, index);
		}
		else if (elem->args[i] == 'I')
		{
			//indirect parsing, check if its a label.
			if (split[i][1] == ':')
			{
				//arg_label
			}
			else
			{
				inter = ft_atoi(split[i] + 1);
				index = convert_to_byte(inter, IND_SIZE, elem->byte_code, index);
			}
			// if it is a label index it properly;
		}
		else
		{
			//register parsing
			inter = ft_atoi(split[i] + 1);
			index = convert_to_byte(inter, REG_SIZE, elem->byte_code, index);
		}
		i++;
	}
	
	printf("Current byte code: %s\n",elem->byte_code);
	printf("Param encoding: %d\n\n",elem->param_encoding);
}
