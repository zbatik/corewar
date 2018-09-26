/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:26:03 by emaune            #+#    #+#             */
/*   Updated: 2018/09/19 14:32:24 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int			check_label_commas(t_main *var, char *line, int ln)
{
	if (is_ignorable_line(line))
		return (0);
	if (is_label(line))
	{
		if (!is_valid_label(line))
		{
			ft_printf(2, lr, "Error: label is invalid\n%s - line #%d\n",
					line, ln);
			free_input(var->input);
			ft_putstr("\e[97m");
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	if (check_commas(line))
	{
		ft_printf(2, lr, "Syntax Error: check commas\n%s - line #%d\n",
				line, ln);
		free_input(var->input);
		ft_putstr("\e[97m");
		exit(EXIT_FAILURE);
	}
	return (1);
}

static int			is_instruction(t_main *var, char *line, int ln)
{
	if (is_name(line) || is_comment(line))
	{
		if (!is_valid_name(line) && is_name(line))
		{
			ft_printf(2, lr, "Error: player name is invalid\n%s - line #%d\n",
					line, ln);
			free_input(var->input);
			ft_putstr("\e[97m");
			exit(EXIT_FAILURE);
		}
		if (!is_valid_comment(line) && is_comment(line))
		{
			ft_printf(2, lr,
				"Error: player comment is invalid\n%s - line #%d\n", line, ln);
			free_input(var->input);
			ft_putstr("\e[97m");
			exit(EXIT_FAILURE);
		}
		return (0);
	}
	return (check_label_commas(var, line, ln));
}

static void			check_mnemonic_and_syntax(char **ins, t_main *var, int ln)
{
	if (!is_valid_mnemonic(ins[0]))
	{
		ft_printf(2,
				lr, "Error: mnemonic is invalid\n%s is not a valid mnemonic",
				ins[0]);
		ft_printf(2, lr, " - line #%d\n", ln);
		free_input(var->input);
		ft_arrdel(&var->ins, arr_len(var->ins));
		ft_putstr("\e[97m");
		exit(EXIT_FAILURE);
	}
	if (ins[1])
		if (ins[1][0] == ',' || ins[1][ft_strlen(ins[1]) - 1] == ',')
		{
			ft_printf(2, lr, "Syntax Error: leading/trailing comma\n");
			ft_printf(2, lr, "%s - line #%d\n", ins[1], ln);
			free_input(var->input);
			ft_arrdel(&var->ins, arr_len(var->ins));
			ft_putstr("\e[97m");
			exit(EXIT_FAILURE);
		}
}

void				error_check_line(t_main *var, char *line, int ln)
{
	char			**ins;

	remove_comment(line);
	if (is_instruction(var, line, ln))
	{
		convert_spaces(line);
		ins = ft_strsplit(line, '\t');
		var->ins = ins;
		check_mnemonic_and_syntax(ins, var, ln);
		check_params(ins, var);
		ft_arrdel(&var->ins, arr_len(var->ins));
	}
}
