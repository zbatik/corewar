/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:44:53 by emaune            #+#    #+#             */
/*   Updated: 2018/09/14 13:08:47 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			free_input(t_input *input)
{
	t_input		*temp;

	while (input->next)
	{
		ft_strdel(&input->line);
		temp = input;
		input = input->next;
		free(temp);
	}
	ft_strdel(&input->line);
	free(input);
}
