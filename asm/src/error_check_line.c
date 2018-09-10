/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:40:01 by emaune            #+#    #+#             */
/*   Updated: 2018/09/10 15:41:15 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			is_instruction(t_main *var, char *line, int ln)
{
	if (is_name(line))
	{
		if (!is_valid_name(line))
		{
			ft_putendl("\x1b[31mError: player name is empty");
			ft_putstr(line);
			ft_putstr(" - line: ");
			free(var->input);
			// free list
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	if (is_comment(line))
	{
		if (!is_valid_comment(line))
		{
			ft_putendl("\x1b[31mError: player comment is empty");
			ft_putstr(line);
			ft_putstr(" - line: ");
			// free list
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	if (is_label(line))
	{
		if (!is_valid_label(line))
		{
			ft_putendl("\x1b[31mError: label is invalid");
			ft_putstr(line);
			ft_putstr(" - line: ");
			ft_putnbr(ln);
			// free list
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	return (1);
}

int			error_check_line(t_main *var, char *line, int ln)
{
	char	**ins;

	if (is_instruction(var, line, ln))
	{
		ins = ft_strsplit(line, ' ');
		if (!is_valid_mnemonic(ins[0]))
		{
			ft_putendl("\x1b[31mError: mnemonic is invalid");
			ft_putstr(ins[0]);
			ft_putstr(" is not a valid mnemonic - line: ");
			ft_putnbr(ln);
			free(var->input);
			// free split and list
			exit(EXIT_FAILURE);
		}
		if (!args_are_valid(ins[1]))
		{
			ft_putendl("\x1b[31mError: the instruction's arguments are invalid");
			ft_putendl(line);
			ft_putstr(" - line: ");
			ft_putnbr(ln);
			// free split and list
			exit(EXIT_FAILURE);
		}
	}
	return (TRUE);
}
