/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 11:38:20 by emaune            #+#    #+#             */
/*   Updated: 2018/09/12 11:44:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void		convert_spaces(char *line)
{
	int		i;
	int		is_first_space;

	i = 0;
	is_first_space = 1;
	while (line[i])
	{
		if ((line[i] == ' ' || line[i] == '\t') && is_first_space)
		{
			line[i] = '\t';
			is_first_space = 0;
			i++;
		}
		if (line[i] == '\t' && !is_first_space)
			line[i] = ' ';
		i++;
	}
}
