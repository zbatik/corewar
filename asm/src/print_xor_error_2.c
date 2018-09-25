/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xor_error_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:52:57 by emaune            #+#    #+#             */
/*   Updated: 2018/09/25 15:18:56 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_xor_error_2(t_main *var, char **par)
{
	int		i;

	i = 0;
	while (par[i])
		i++;
	if (i > 3 || i < 3)
	{
		ft_printf(2, lr, "Error: too many/too few arguments.\nExpected:\txor");
		ft_printf(2, lr, " [T_REG | T_DIR | T_IND], [T_REG | T_DIR | T_IND],");
		ft_printf(2, lr, " [T_REG].\nGot:\t\t\"%s\" - line #%d\n",
				var->temp_input->line, var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
}
