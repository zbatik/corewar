/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_listinfo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:27:06 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/07 10:27:07 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_bool	run_bytecode(t_input **var)
{
	t_input *tmp;
	int		count;

	tmp = *var;
	count = 0;
	while (tmp != NULL)
	{
		if (is_wsstring(tmp->line) == FALSE)
		{
			if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
				&& is_comment(tmp->line) == FALSE)
			{
				gen_bytecode(*var, tmp, count);
				count += tmp->byte_count;
			}
		}
		tmp = tmp->next;
	}
	return (TRUE);
}

void	run_bytesize(t_input **tmp, int *count)
{
	*count = *count + instruction_byte_size(*tmp);
	tmp[0]->param_encoding = string_to_encoding(tmp[0]->args);
	if (inst_to_enum(tmp[0]->line) == 16)
		tmp[0]->param_encoding = 64;
	if (tmp[0]->param_encoding != 0)
	{
		tmp[0]->byte_count++;
		*count = *count + 1;
	}
}

t_bool	parse_listinfo(t_main *var)
{
	t_input *tmp;

	tmp = var->input;
	var->total_player_size = 0;
	while (tmp != NULL)
	{
		if (is_wsstring(tmp->line) == FALSE)
		{
			if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
				&& is_comment(tmp->line) == FALSE)
				run_bytesize(&tmp, (int *)&var->total_player_size);
			if (is_label(tmp->line) == TRUE)
			{
				tmp->byte_count = var->total_player_size;
				tmp->is_label = TRUE;
			}
		}
		tmp = tmp->next;
	}
	if (var->total_player_size > CHAMP_MAX_SIZE)
	{
		ft_putendl("Error: Champion to big");
		exit(exit_function(var));
	}
	return (run_bytecode(&var->input));
}
