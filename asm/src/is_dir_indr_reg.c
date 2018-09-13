/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir_indr_reg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 11:10:21 by emaune            #+#    #+#             */
/*   Updated: 2018/09/13 12:54:28 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	label_exists(char *label, t_main *var)
{
	t_input *i;

	i = var->input;
	while (i)
	{
		if (ft_strnequ(i->line, label, ft_strlen(label)))
			return (1);
		i = i->next;
	}
	ft_putendl("\x1b[31;1mError: Label does not exist");
	ft_putstr(label);
	ft_putstr(" - line #");
	ft_putnbr(var->temp_input->line_no);
	//free list and split;
	exit(EXIT_FAILURE);
}

static int	is_number(char *n)
{
	int		i;

	i = 0;
	if (*n == '\0')
		return (0);
	if (*n == '-')
		n++;
	while (n[i])
	{
		if (!(n[i] >= '0' && n[i] <= '9') || n[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int			is_direct(char *arg, t_main *var)
{
	char	*t;

	t = ft_strtrim(arg);
	if (*t == '%' && is_number(t + 1))
	{
		ft_strdel(&t);
		return (1);
	}
	if (*t == '%')
		if (*(t + 1) == ':' )
			if (label_exists(t + 2, var))
			{
				ft_strdel(&t);
				return (1);
			}
	ft_strdel(&t);
	return (0);
}

int			is_indirect(char *arg, t_main *var)
{
	char	*t;

	t = ft_strtrim(arg);
	if (*t == ':' ) 
		if (label_exists(t + 1, var))
		{
			ft_strdel(&t);
			return (1);
		}
	if (is_number(t))
	{
		ft_strdel(&t);
		return (1);
	}
	ft_strdel(&t);
	return (0);
}

int			is_register(char *arg, t_main *var)
{
	char	*t;

	t = ft_strtrim(arg);
	if (*t == 'r')
		if (is_number(t + 1))
		{
			if (ft_atoi(t + 1) >= 1 && ft_atoi(t + 1) <= 16)
			{
				ft_strdel(&t);
				return (1);
			}
			else
			{
				ft_strdel(&t);
				ft_putendl("\x1b[31;1mError: Register is out of scope i.e. there are only 16 registers (1-16).");
				ft_putstr(var->temp_input->line);
				ft_putstr(" - line #");
				ft_putnbr(var->temp_input->line_no);
				//freee split/list
				free(var->ins);
				exit(1);
			}
		}
	ft_strdel(&t);
	return (0);
}
