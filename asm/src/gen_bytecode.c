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

void	convert_to_byte(unsigned int num, t_byte *code)
{
	*code = num;
}

//*(t_byte*)&inter = ft_atoi(split[i]);
void	gen_bytecode(t_input *ahead, t_input *elem, int curr_byte_count)
{
	int 	i;
	char	*tmp;
	char	**split;
	char	*curr;
	int		inter;
	t_opnum op;
	t_input	*label;

	op = inst_to_enum((char*)elem->line);
	elem->byte_code[0] = (t_byte *)malloc(sizeof(t_byte));
	printf("Op translated: %d\n",(unsigned char) (index_opinfo(op)).op_number);
	inter = rev_endian((unsigned int)(index_opinfo(op)).op_number);
	ft_memmove(elem->byte_code[0], &inter, sizeof(t_byte));
	tmp = (char *)elem->line;
    while(ft_isws(*tmp) == FALSE && *tmp != '\0')
        tmp++;
    while(ft_isws(*tmp) == TRUE && *tmp != '\0')
        tmp++;
    split = ft_strsplit(tmp, ',');
    i = 0;
	while (elem->args[i] != '\0')
	{
		curr = split[i];
		while(ft_isws(*curr) == TRUE)
			curr++; 
		if (elem->args[i] == 'D')
		{
			if (curr[1] == ':')
			{
				printf("Identified as label\n");
				label = get_label(ahead, curr + 2);
				printf("Label is: %s\n",label->line);
				inter = label->byte_count;
				if (inter < curr_byte_count)	
				{	
					inter = (curr_byte_count -  inter);
				}
				else
					inter = (inter -  curr_byte_count);
			}
			else
				inter = ft_atoi(curr + 1);
			inter = (int) rev_endian((unsigned int) inter);
			elem->byte_code[i + 1] = (t_byte *)malloc(sizeof(t_byte) * DIR_SIZE);
			ft_memmove(elem->byte_code[i +1], &inter, sizeof(t_byte) * DIR_SIZE);
			printf("%s has value %d and i is: %d\n", curr, inter, i);
		}
		else if (elem->args[i] == 'I')
		{
			elem->byte_code[i + 1] = (t_byte *)malloc(sizeof(t_byte) * IND_SIZE);
			inter = ft_atoi(curr);
			inter = (int) rev_endian((unsigned int) inter);
			ft_memmove(elem->byte_code[i + 1], &inter, sizeof(t_byte) * IND_SIZE);
			printf("%s has value %x and i is: %d\n",curr, elem->byte_code[i + 1][1], i);
			
		}
		else
		{
			inter = ft_atoi(curr + 1);
			elem->byte_code[i + 1] = (t_byte *)malloc(sizeof(t_byte) * REG_SIZE);
			ft_memmove(elem->byte_code[i + 1], &inter, sizeof(t_byte) * REG_SIZE);
			printf("%s has value %x and i is: %d\n",curr, elem->byte_code[i + 1][0], i);
		}
		i++;
	}
	
}
