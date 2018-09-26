/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_st_error_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:43:59 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 12:47:46 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_st_error_2(t_main *var, char **par)
{
	int		i;

	i = 0;
	while (par[i])
		i++;
	if (i > 2 || i < 2)
	{
		ft_printf(2, lr, "Error: too many/too few arguments.\n");
		ft_printf(2, lr, "Expected:\tst [T_REG], [T_IND | T_REG].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		exit(EXIT_FAILURE);
	}
}
