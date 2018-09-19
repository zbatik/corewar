/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:46:59 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/18 15:37:49 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

static int	g_smalldir[] = {9, 10, 11, 12, 13, 15, 16};

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

int		is_smalldir(int opnum, int arg_num)
{
	int i;

	i = 0;
	while (i < NUM_SMALL_DIR)
		if (g_smalldir[i++] == opnum)
			return(TRUE);
	return (FALSE);
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


void	gen_bytecode(t_input *ahead, t_input *elem, int curr_byte_count)
{
	int 	i;
	char	*tmp;
	char	**split;
	char	*curr;
	int		inter;
	int		tmp_size;

	t_opnum op;

	op = inst_to_enum((char*)elem->line);
	elem->byte_code[0] = (t_byte *)malloc(sizeof(t_byte));
	inter = (index_opinfo(op)).op_number;
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
		if (elem->args[i] == 'D' || elem->args[i] == 'd')
		{
			if (elem->args[i] == 'D')
				tmp_size = DIR_SIZE;
			else
				tmp_size = ASM_DIR;
			if (curr[1] == ':')
			{
				inter = get_label(ahead, curr + 2)->byte_count;
				inter = (inter - (curr_byte_count + elem->byte_count)) + 1;
			}
			else
				inter = ft_atoi(curr + 1);
			inter = (int) rev_endian((unsigned int) inter);
			if (tmp_size == ASM_DIR)
				inter = inter << 16 | inter >> 16;
			elem->byte_code[i + 1] = (t_byte *)malloc(sizeof(t_byte) * tmp_size);
			ft_memmove(elem->byte_code[i +1], &inter, sizeof(t_byte) * tmp_size);
		}
		else if (elem->args[i] == 'I')
		{
			elem->byte_code[i + 1] = (t_byte *)malloc(sizeof(t_byte) * IND_SIZE);
			if (curr[0] == ':')
			{
				inter = get_label(ahead, curr + 1)->byte_count;
				inter = (inter - curr_byte_count);
			}
			else
				inter = ft_atoi(curr);
			inter = (int) rev_endian((unsigned int) inter);
			inter = inter << 16 | inter >> 16;
			ft_memmove(elem->byte_code[i + 1], &inter, sizeof(t_byte) * IND_SIZE);		
		}
		else
		{
			inter = ft_atoi(curr + 1);
			elem->byte_code[i + 1] = (t_byte *)malloc(sizeof(t_byte) * ASM_REG);
			ft_memmove(elem->byte_code[i + 1], &inter, sizeof(t_byte) * ASM_REG);
		}
		i++;
	}
	
}
