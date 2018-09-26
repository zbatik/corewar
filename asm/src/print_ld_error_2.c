/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ld_error_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:04:09 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 12:25:52 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


void		print_ld_error_2(t_main *var, char **par)
{
	int		i;

	i = 0;
	while (par[i])
		i++;
	if (i > 2 || i < 2)
	{
		ft_printf(2, lr, "Error: too many/too few arguments.\n");
		ft_printf(2, lr, "Expected:\tld [T_DIRECT | T_IND], [T_REG].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n",
				var->temp_input->line, var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		free_input(var->input);
		exit(EXIT_FAILURE);
	}	
}
