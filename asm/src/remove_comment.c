/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_comment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:27:45 by emaune            #+#    #+#             */
/*   Updated: 2018/09/11 13:32:31 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void			remove_comment(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '#')
		{
			i--;
			while ((line[i] == ' ' || line[i] == '\t' || line[i] == '\v')
					&& i >= 0)
				i--;
			i++;
			line[i] = '\0';
			break ;
		}
		i++;
	}
}