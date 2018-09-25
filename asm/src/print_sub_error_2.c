/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sub_error_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:00:42 by emaune            #+#    #+#             */
/*   Updated: 2018/09/25 14:02:26 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_sub_error_2(t_main *var, char **par)
{
	int		i;

	i = 0;
	while (par[i])
		i++;
	if (i > 3 || i < 3)
	{
		ft_printf(2, lr, "Error: too many/too few arguments.\nExpected:\tsub ");
		ft_printf(2, lr, "[T_REG], [T_REG], [T_REG].\nGot\t\t\"%s\" - line #%d",
				var->temp_input->line, var->temp_input->line_no);
		free_split(par);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
}
