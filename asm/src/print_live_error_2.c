/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_live_error_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:00:18 by emaune            #+#    #+#             */
/*   Updated: 2018/09/26 12:23:41 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		print_live_error_2(t_main *var, char **par)
{
	int		i;

	i = 0;
	while (par[i])
		i++;
	if (i > 1)
	{
		ft_printf(2, lr, "Error: too many arguments.\n");
		ft_printf(2, lr, "Expected:\tlive [T_DIRECT].\n");
		ft_printf(2, lr, "Got:\t\t\"%s\" - line #%d\n", var->temp_input->line,
				var->temp_input->line_no);
		ft_arrdel(&var->ins, arr_len(var->ins));
		free_input(var->input);
		free_split(par);
		exit(EXIT_FAILURE);
	}
}
