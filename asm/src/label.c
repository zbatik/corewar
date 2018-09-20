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

int	arg_byte_count(char *str)
{
	int		ret;
    char    *tmp;
	ret = 0;
	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp == 'I')
			ret += IND_SIZE;
		else if(*tmp == 'R')
			ret += ASM_REG;
        else if(*tmp == 'd')
            ret += ASM_DIR;
        else
            ret += DIR_SIZE;
		tmp++;
	}
	return (ret);
}

int string_to_encoding_help(char *tmp)
{
    if (ft_strncmp(tmp, "IIR", 3) == 0)
        return (IIR);
    else if (ft_strncmp(tmp, "IDR", 3) == 0)
        return (IDR);
    else if (ft_strncmp(tmp, "DRR", 3) == 0)
        return(DRR);
    else if (ft_strncmp(tmp, "DIR", 3) == 0)
        return(DIR);
    else if (ft_strncmp(tmp, "DDR", 3) == 0)
        return(DDR);
    else if (ft_strncmp(tmp, "IR", 2) == 0)
        return (IR);
    else if (ft_strncmp(tmp, "DR", 2) == 0)
        return (DR);
    else if (ft_strncmp(tmp, "RI", 2) == 0)
        return(RI);
    else if (ft_strncmp(tmp,  "RR", 2) == 0)
        return(RR);
    return (0);
}

int string_to_encoding (char str[4])
{
    char    tmp[4];
    int     i;

    i = 0;
    while (i < 4)
    {
        tmp[i] = ft_toupper(str[i]);
        i++;
    }
    tmp[i] = '\0';
    if (ft_strncmp(tmp, "RRR", 3) == 0)
        return (RRR);
    else if (ft_strncmp(tmp, "RIR", 3) == 0)
        return (RIR);
    else if (ft_strncmp(tmp, "RDR", 3) == 0)
        return (RDR);
    else if (ft_strncmp(tmp, "RRD", 3) == 0)
    	return (RRD);
    else if (ft_strncmp(tmp, "RDD", 3) == 0)
        return (RDD);
    else if (ft_strncmp(tmp, "RID", 3) == 0)
        return (RID);
    else if (ft_strncmp(tmp, "IRR", 3) == 0)
        return (IRR);
    return(string_to_encoding_help(tmp));
}

char    arg_type_def(char *curr, t_opnum op, int i)
{
	while (ft_isws(*curr) == TRUE)
		curr++;
	if (curr[0] == '%')
	{
	    if (is_smalldir(op, i) == TRUE)
	        return('d');
	    else
	        return('D');
	}
	else if (curr[0] == 'r')
	    return('R');
    return('I');
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
       	input->args[i] = arg_type_def(curr, op, i);
        i++;
    }
    input->args[i] = '\0';
    input->byte_count = arg_byte_count(input->args) + 1;
}

int    instruction_byte_size(t_input   *input)
{
    t_opnum op;

    op = inst_to_enum((char*)input->line);
    instruction_arg_size(op, input);
    return (input->byte_count);
}