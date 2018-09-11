/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:40:01 by emaune            #+#    #+#             */
/*   Updated: 2018/09/11 14:53:22 by emaune           ###   ########.fr       */
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
	if (is_ignorable_line(line))
		return (0);
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

void			error_check_line(t_main *var, char *line, int ln)
{
	char	**ins;
	char	*no_spaces;

	if (is_instruction(var, line, ln))
	{
		no_spaces = remove_spaces(line);
		line = no_spaces;
		remove_comment(line);
		ins = ft_strsplit(line, ' ');
		var->ins = ins;
		if (!is_valid_mnemonic(ins[0]))
		{
			ft_putendl("\x1b[31mError: mnemonic is invalid");
			ft_putstr(ins[0]);
			ft_putstr(" is not a valid mnemonic - line: ");
			ft_putnbr(ln);
			ft_strdel(&no_spaces);
			free(var->input);
			// free split and list
			exit(EXIT_FAILURE);
		}
		check_params(ins, var);
		ft_strdel(&no_spaces);
	}
}
