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
#include <stdio.h>


/*
typedef struct		s_input
{
	char			*line;
	char			args[MAX_ARGS_NUMBER];
	int				line_no;
	int				byte_count;
	t_byte			*byte_code[MAX_ARGS_NUMBER + 1];
	t_byte			param_encoding;
	t_bool			is_label;
	t_opnum			instruction_type;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

typedef struct s_main 
{
	t_input			*input;
	t_input			*temp_input;
	unsigned int	total_player_size;
	char			**ins;
}				t_main;
*/

void	free_input_whole(t_input **input)
{
	t_input *tmp;
	int		i;

	i = 1;
	if (input != NULL && (tmp = *input) != NULL)
	{
		//fprintf(stderr, "0\n");
		ft_memdel((void **)&tmp->line);
		//fprintf(stderr, "1\n");
		ft_memdel((void **)&tmp->byte_code[0]);
		//fprintf(stderr, "2\n");
		while (i < MAX_ARGS_NUMBER && tmp->args[i - 1] != '\0')
		{
			//fprintf(stderr, "%d\n",i);
			ft_memdel((void **)&tmp->byte_code[i++]);
		}
		//free(tmp->byte_code);
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
		if (is_wsstring(prev->line) == FALSE)
			if (is_label(prev->line) == FALSE && is_name(prev->line) == FALSE
					&& is_comment(prev->line) == FALSE)
				free_input_whole(&prev);
	}
	return (0);
}
