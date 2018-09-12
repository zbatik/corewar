/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <emaune@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:00:15 by emaune            #+#    #+#             */
/*   Updated: 2018/09/11 13:09:45 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		check_params_2(char **args, t_main *var)
{
	if (ft_strequ(args[0], "xor"))
		check_xor(args, var);
	if (ft_strequ(args[0], "zjmp"))
		check_zjmp(args, var);
	if (ft_strequ(args[0], "ldi"))
		check_ldi(args, var);
	if (ft_strequ(args[0], "sti"))
		check_sti(args, var);
	if (ft_strequ(args[0], "fork"))
		check_fork(args, var);
	if (ft_strequ(args[0], "lld"))
		check_lld(args, var);
	if (ft_strequ(args[0], "lldi"))
		check_lldi(args, var);
	if (ft_strequ(args[0], "lfork"))
		check_lfork(args, var);
	if (ft_strequ(args[0], "aff"))
		check_aff(args, var);
}

void		check_params(char **args, t_main *var)
{
	if (ft_strequ(args[0], "live"))
		check_live(args, var);
	if (ft_strequ(args[0], "ld"))
		check_ld(args, var);
	if (ft_strequ(args[0], "st"))
		check_st(args, var);
	if (ft_strequ(args[0], "add"))
		check_add(args, var);
	if (ft_strequ(args[0], "sub"))
		check_sub(args, var);
	if (ft_strequ(args[0], "and"))
		check_and(args, var);
	if (ft_strequ(args[0], "or"))
		check_or(args, var);
	check_params_2(args, var);
}
