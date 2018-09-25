/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 13:34:43 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/25 18:47:03 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void	print_hex(int n, int cl)
{
	char	out[12];
	char	*hex;
	int		i;

	i = 0;
	ft_bzero(out, 12);
	hex = "0123456789abcdef";
	if (n == 0)
		ft_putchar_cl('0', cl);
	while (n != 0)
	{
		out[i] = hex[n % 16];
		n = n / 16;
		i++;
	}
	i = 1;
	if (out[1] == 0)
	{
		ft_putchar_cl('0', cl);
		i--;
	}
	while (out[i])
		ft_putchar_cl(out[i--], cl);
}

static int	highlight_pc(t_core *core, int pc)
{
	int i;

	i = -1;
	while (++i < core->num_processes)
	{
		if (core->processes[i].pc == pc)
			return (1);
	}
	return (0);
}

void		print_mem(t_core *core)
{
	int i;
	int highlight;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			ft_putchar('\n');
		highlight = highlight_pc(core, i);
		ft_putstr(highlight ? "\033[7m" : "");
		print_hex(core->mem[i], core->colouring[i]);
		ft_putstr(highlight ? "\033[m" : "");
		ft_putchar(' ');
		i++;
	}
	ft_putendl("");
}

void		print_cylce_info(t_core *core)
{
	ft_printf(1, y, "END OF CYCLE BREAKDOWN\n");
	ft_printf(1, m, "number of processes:\t%d\n", core->num_processes);
	ft_printf(1, m, "round number:\t\t%d\n", core->count.cycles);
	ft_printf(1, m, "totol executed turns:\t%d\n", core->count.total_turns);
	ft_printf(1, m, "cycles to die:\t\t%d\n", core->count.cycles_to_die);
	ft_printf(1, m, "live count this cycle:\t%d\n", core->count.lives);
	ft_printf(1, m, "number players alive:\t%d\n", num_alive(core));
}
