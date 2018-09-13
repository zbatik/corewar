/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_name_comment.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:10:23 by emaune            #+#    #+#             */
/*   Updated: 2018/09/13 14:03:50 by emaune           ###   ########.fr       */
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

int			count_inv(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\"')
			count++;
		i++;
	}
	return (count);
}

int			is_valid_name(char *line)
{
	int		i;
	char	*t;
	char	**str;

	i = 0;
	convert_spaces(line);
	str = ft_strsplit(line, '\t');
	while (str[i])
		i++;
	if (i == 1 || i > 2)
	{
		ft_arrdel(&str, i);
		return (0);	
	}
	t = ft_strtrim(str[1]);
	if (t[0] == '\"' && t[ft_strlen(t) - 1] == '\"' && ft_strlen(t) > 2 && count_inv(t) == 2)
	{
		ft_arrdel(&str, i);
		ft_strdel(&t);
		return (1);
	}
	ft_strdel(&t);
	ft_arrdel(&str, i);
	return (0);
}

int			is_valid_comment(char *line)
{
	int		i;
	char	**str;
	char	*t;

	i = 0;
	convert_spaces(line);
	str = ft_strsplit(line, '\t');
	while (str[i])
		i++;
	if (i == 1 || i > 2)
	{
		ft_arrdel(&str, i);
		return (0);	
	}
	t = ft_strtrim(str[1]);
	if (t[0] == '\"' && t[ft_strlen(t) - 1] == '\"' && ft_strlen(t) > 2 && count_inv(t) == 2)
	{
		ft_arrdel(&str, i);
		ft_strdel(&t);
		return (1);
	}
	ft_strdel(&t);
	ft_arrdel(&str, i);
	return (0);
}
