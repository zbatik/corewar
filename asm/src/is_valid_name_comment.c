/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_name_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:10:23 by emaune            #+#    #+#             */
/*   Updated: 2018/09/10 14:49:11 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			is_name(char *line)
{
	if (ft_strnequ(line, NAME_CMD_STRING, 5))
		return (1);
	return (0);
}

int			is_comment(char *line)
{
	if (ft_strnequ(line, COMMENT_CMD_STRING, 8))
		return (1);
	return (0);
}

int			is_valid_name(char *line)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_strsplit(line, ' ');
	while (str[i])
		i++;
	if (i == 1 || i > 2)
	{
		ft_arrdel(&str, i);
		return (0);	
	}
	if (str[1][0] == '\"' && str[1][ft_strlen(str[1]) - 1] == '\"' && ft_strlen(str[1]) > 2)
	{
		ft_arrdel(&str, i);
		return (1);
	}
	ft_arrdel(&str, i);
	return (0);
}

int			is_valid_comment(char *line)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_strsplit(line, ' ');
	while (str[i])
		i++;
	if (i == 1 || i > 2)
	{
		ft_arrdel(&str, i);
		return (0);	
	}
	if (str[1][0] == '\"' && str[1][ft_strlen(str[1]) - 1] == '\"' && ft_strlen(str[1]) > 2)
	{
		ft_arrdel(&str, i);
		return (1);
	}
	ft_arrdel(&str, i);
	return (0);
}
