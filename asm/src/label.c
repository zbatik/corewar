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

int string_to_encoding (char str[4])
{
    if (ft_strncmp(str, "RRR", 3) == 0)
        return (RRR);
    else if (ft_strncmp(str, "RIR", 3) == 0)
        return (RIR);
    else if (ft_strncmp(str, "RDR", 3) == 0)
        return (RDR);
    else if (ft_strncmp(str, "RRD", 3) == 0)
    	return (RRD);
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
    else if (ft_strncmp(str, "RI", 2) == 0)
        return(RI);
    else if (ft_strncmp(str,  "RR", 2) == 0)
        return(RR);
    return(0);
}

void    instruction_arg_size(t_opnum op, t_input *input)
{
    char    **split;
    int     num_args;
    char    *tmp;
    char    *curr;
    int     i;

    i = 0;
    tmp = input->line;
    ft_bzero(&input->args, MAX_ARGS_NUMBER);
    while(ft_isws(*tmp) == FALSE && *tmp != '\0')
        tmp++;
    while(ft_isws(*tmp) == TRUE && *tmp != '\0')
        tmp++;
    split = ft_strsplit(tmp, ',');
    num_args = (index_opinfo(op)).num_args;
    while(split != NULL && i < num_args)
    {
        curr = split[i];
        while (ft_isws(*curr) == TRUE)
            curr++;
        if (curr[0] == '%')
            input->args[i] = 'D';
        else if (curr[0] == 'r')
            input->args[i] = 'R';
        else
        {
        	// make tests to change between big i and small I
        	input->args[i] = 'I';
        }
        i++;
    }
    input->args[i] = '\0';
    input->byte_count = arg_byte_count(input->args) + 1;
}

int    instruction_byte_size(t_input   *input)
{
    t_opnum op;

    op = inst_to_enum((char*)input->line);
    if (DEBUG)
    {
        //ft_putstr("Calculating byte lenght of: ");
        //ft_putendl(input->line);
		//ft_putstr("Recognised as: ");
		//ft_putendl((index_opinfo(op)).instruction);
		//ft_putstr("Calculated byte size of: \n");
        instruction_arg_size(op, input);
		//ft_putnbr(input->byte_count);
		//ft_putchar('\n');
    }
    return (input->byte_count);
}