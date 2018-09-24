/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 13:29:50 by emaune            #+#    #+#             */
/*   Updated: 2018/09/16 13:52:51 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			check_multiple_name(t_main *var)
{
	t_input		*a;
	t_input		*b;

	a = var->input;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (is_name(b->line) && is_name(a->line))
			{
				ft_putendl("\x1b[31;1mError: Multiple player name detected");
				free_input(var->input);
				ft_putstr("\e[97m");
				exit(EXIT_FAILURE);
			}
			b = b->next;
		}
		a = a->next;
	}
}

void			check_multiple_comment(t_main *var)
{
	t_input		*a;
	t_input		*b;

	a = var->input;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (is_comment(b->line) && is_comment(a->line))
			{
				ft_putendl("\x1b[31;1mError: Multiple player comment detected");
				free_input(var->input);
				ft_putstr("\e[97m");
				exit(EXIT_FAILURE);
			}
			b = b->next;
		}
		a = a->next;
	}
}

void			check_duplicate_label(t_main *var)
{
	t_input		*a;
	t_input		*b;

	a = var->input;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (is_label(a->line) && is_label(b->line))
				if (ft_strequ(a->line, b->line))
				{
					ft_putendl("\x1b[31;1mError: Duplicate label detected");
					free_input(var->input);
					ft_putstr("\e[97m");
					exit(EXIT_FAILURE);
				}
			b = b->next;
		}
		a = a->next;
	}
}
