/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fork_gen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:32:02 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 13:25:34 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

static int	ft_fork_gen(t_core *core, t_process *cursor, t_opnum op)
{
	int jump;
	int	byte_count;
	int success;

	byte_count = general_processing(core, cursor, op);
	if (byte_count == 1)
		return (byte_count);
	if (op == e_fork)
		jump = PC(get_dir(core, cursor, 1, op) % IDX_MOD);
	else
		jump = PC(get_dir(core, cursor, 1, op));
	success = duplicate_process(core, cursor, jump);
	if (success)
		return (byte_count);
	if (PBP)
		ft_printf(1, na, "cursor created at %d\n", jump);
	return (byte_count);
}

int			ft_fork(t_core *core, t_process *cursor)
{
	return (ft_fork_gen(core, cursor, e_fork));
}

int			ft_lfork(t_core *core, t_process *cursor)
{
	return (ft_fork_gen(core, cursor, e_lfork));
}
