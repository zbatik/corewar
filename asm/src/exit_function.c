/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 10:24:32 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/20 10:24:33 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_input_min(t_input **input)
{
	t_input *tmp;

	if (input != NULL && (tmp = *input) != NULL)
	{
		free(tmp->line);
		free(tmp);
		input = NULL;
	}
}

void	free_input_whole(t_input **input)
{
	int		i;

	i = 1;
	if (input != NULL)
	{
		free(input[0]->line);
		free(input[0]->byte_code[0]);
		while (i < MAX_ARGS_NUMBER && input[0]->args[i - 1] != '\0')
			free(input[0]->byte_code[i++]);
		free(*input);
		input = NULL;
	}
}

int		exit_function(t_main *var)
{
	t_input	*curr;
	t_input	*prev;

	curr = var->input;
	while (curr != NULL)
	{
		prev = curr;
		curr = prev->next;
		if (is_wsstring(prev->line) == TRUE || is_label(prev->line) == TRUE
			|| is_name(prev->line) == TRUE || is_comment(prev->line) == TRUE)
			free_input_min(&prev);
		else
			free_input_whole(&prev);
		prev = NULL;
	}
	free(var->ins);
	return (0);
}
