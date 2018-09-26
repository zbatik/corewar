/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aff_error_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:23:48 by emaune            #+#    #+#             */
/*   Updated: 2018/09/25 13:32:33 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			print_aff_error_2(t_main *var, char **par)
{
	int			i;

	i = 0;
	while (par[i])
		i++;
	if (i > 1)
	{
		ft_printf(2, lr, "Error: too many arguments.\nExpected:\taff [T_REG].");
		ft_printf(2, lr, "\nGot:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		free_split(par);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		exit(EXIT_FAILURE);
	}
}
