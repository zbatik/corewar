/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_and_too_many_too_few_args.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:09:57 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 14:36:29 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


void		print_error_and_2(t_main *var, char **par)
{
	int		i;

	i = 0;
	while (par[i])
		i++;
	if (i > 3 || i < 3)
	{
		ft_printf(2, lr, "Error: too many/too few arguments.\n");
		ft_printf(2, lr, "Expected: and [T_REG | T_DIR | T_IND], ");
		ft_printf(2, lr, "[T_REG | T_DIR | T_IND], [T_REG].\nGot: \"%s\"",
				var->temp_input->line);
		ft_printf(2, lr, " - line #%d\n", var->temp_input->line_no);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_split(par);
		exit(EXIT_FAILURE);
	}
}
