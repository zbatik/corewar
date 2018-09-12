/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_live_and_ld.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:16:01 by emaune            #+#    #+#             */
/*   Updated: 2018/09/12 11:48:38 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				check_live(char **args, t_main *var)
{
	int			i;
	char		**par;

	i = 0;
	par = ft_strsplit(args[1], ',');
	ft_putendl("hello");
	while (par[i])
		i++;
	if (i > 1)
	{
		ft_putendl("\x1b[31mError: live has too many arguments i.e. live [T_DIRECT].");
		ft_putstr(var->temp_input->line);
		ft_putstr(" - line: ");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free split and list;
	}
	if (!is_direct(*par, var))
	{
			ft_putendl("\x1b[31mError: live has invalid argument i.e. live [T_DIRECT].");
		ft_putstr(var->temp_input->line);
		ft_putstr(" - line: ");
		ft_putnbr(var->temp_input->line_no);
		exit(EXIT_FAILURE);
		//free  split and list
	}
	return (1);

}

int				check_ld(char **args, t_main *var)
{
		var = NULL;
	args = NULL;
	return (1);
}
