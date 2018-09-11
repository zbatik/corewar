/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 14:10:23 by emaune            #+#    #+#             */
/*   Updated: 2018/09/11 15:33:14 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int			count_spaces(char *line)
{
	int				i;
	int				spaces;
	int				is_first_space;

	i = 0;
	spaces = 0;
	is_first_space = 1;
	while (line[i])
	{
		if ((line[i] == ' ' || line[i] == '\t') && is_first_space)
		{
			is_first_space = 0;
			i++;
		}
		if ((line[i] == ' ' || line[i] == '\t') && !is_first_space)
			spaces++;
		i++;
	}
	return (spaces);
}

char				*remove_spaces(char *line)
{
	char			*no_spaces;
	int				i;
	int				j;
	int				is_first_space;

	i = 0;
	j = 0;
	is_first_space = 1;
	no_spaces = (char*)malloc(sizeof(char)
			* ft_strlen(line) - count_spaces(line) + 1);
	while (line[i])
	{
		if ((line[i] == ' ' || line[i] == '\t') && is_first_space)
		{
			is_first_space = 0;
			no_spaces[j] = line[i];
			i++;
			j++;
		}
		if (line[i] != ' ' && line[i] != '\t')
		{
			no_spaces[j] = line[i];
			j++;
		}
		i++;
	}
	no_spaces[j] = '\0';
	ft_putendl(line);
	ft_putendl(no_spaces);
	return (no_spaces);
}
