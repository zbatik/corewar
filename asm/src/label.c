/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:26:08 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/05 18:25:46 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

int	arg_byte_count(char *str)
{
	int	ret;

	ret = 0;
	while (*str != '\0')
	{
		if (*str == 'I')
			ret += 2;
		else
			ret += 4;
		str++;
	}
	return (ret);
}

int string_to_encoding (char str[3])
{
    if (ft_strncmp(str, "RRR", 3) == 0)
        return (RRR);
    else if (ft_strncmp(str, "RIR", 3) == 0)
        return (RIR);
    else if (ft_strncmp(str, "RDR", 3) == 0)
        return (RDR);
    else if (ft_strncmp(str, "IRR", 3) == 0)
        return (IRR);
    else if (ft_strncmp(str, "IIR", 3) == 0)
        return (IIR);
    else if (ft_strncmp(str, "IDR", 3) == 0)
        return (IDR);
    else if (ft_strncmp(str, "DRR", 3) == 0)
        return (DRR);
    else if (ft_strncmp(str, "DIR", 3) == 0)
        return (DIR);
    else if (ft_strncmp(str, "DDR", 3) == 0)
        return(DDR);
    else if (ft_strncmp(str, "IR", 2) == 0)
        return (IR);
    else if (ft_strncmp(str, "DR", 2) == 0)
        return (DR);
    return(0);
}

int instruction_arg_size(t_opnum op, const char *instruction_line)
{
    char    **split;
    int     num_args;
    char    *tmp;
    int     i;
    char    arg_arr[4];

    i = 0;
    tmp = (char *)instruction_line;
    ft_bzero(&arg_arr, 4);
    while(ft_isws(*tmp) == FALSE && *tmp != '\0')
        tmp++;
    while(ft_isws(*tmp) == TRUE && *tmp != '\0')
        tmp++;
    split = ft_strsplit(tmp, ',');
    num_args = (index_opinfo(op)).num_args;
    while(split != NULL && i < num_args)
    {
        if (split[i][0] == '%')
            arg_arr[i] = 'I';
        else if (split[i][0] == 'r')
            arg_arr[i] = 'R';
        else
        	arg_arr[i] = 'D';
        i++;
    }
    arg_arr[i] = '\0';
   	printf("string to encoding: %d, and str is: %s\n", string_to_encoding(arg_arr), arg_arr);
    return (arg_byte_count(arg_arr));
}

int instruction_byte_size(char *instruction_line)
{
    t_opnum op;
    int     byte_size;

    byte_size = 0;
    op = inst_to_enum((char*)instruction_line);
    if (DEBUG)
    {
        ft_putstr("Calculating byte lenght of: ");
        ft_putendl((char*)instruction_line);
		ft_putstr("Recognised as: ");
		ft_putendl((index_opinfo(op)).instruction);
		ft_putstr("Calculated byte size of: \n");
		byte_size = instruction_arg_size(op, instruction_line);
		ft_putnbr(byte_size);
		ft_putchar('\n');
    }
    return (byte_size);
}