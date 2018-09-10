/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:24:20 by emaune            #+#    #+#             */
/*   Updated: 2018/09/10 15:40:00 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			is_valid_label(char *str)
{
	int		i;
	int		j;
	int		flag;

	i = 0;
	while (str[i] && str[i] != ':')
	{
		j = 0;
		flag = 0;
		while (LABEL_CHARS[j])
		{
			if (str[i] == LABEL_CHARS[j])
			{
				flag = 1;
				break ;
			}
			j++;
		}
		if (!flag)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int			is_label(char *str)
{
	if (ft_strlen(str) > 1)
		if (str[ft_strlen(str) - 1] == ':')
		return (TRUE);
	return (FALSE);
}
