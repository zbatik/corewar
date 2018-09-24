/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_or_error_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:31:34 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 14:40:22 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			print_or_error_2(t_main *var, char **par)
{
	int			i;

	i = 0;
	while (par[i])
		i++;
	if (i > 3 || i < 3)
	{
		ft_printf(2, lr, "Error: too many/too few arguments.\nExpected: or");
		ft_printf(2, lr, " [T_REG | T_DIR | T_IND], [T_REG | T_DIR | T_IND], ");
		ft_printf(2, lr, "[T_REG].\nGot: \"%s\" - line #%d\n",
				var->temp_input->line, var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		exit(EXIT_FAILURE);
	}
}
