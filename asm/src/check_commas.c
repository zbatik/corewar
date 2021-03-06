/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commas.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:51:06 by emaune            #+#    #+#             */
/*   Updated: 2018/09/14 11:52:38 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int				check_commas(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			if (line[i + 1] == ',')
				return (1);
		i++;
	}
	return (0);
}
