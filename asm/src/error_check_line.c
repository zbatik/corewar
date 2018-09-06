/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:40:01 by emaune            #+#    #+#             */
/*   Updated: 2018/09/06 15:30:31 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int			error_check_line(char *line)
{
	char	**ins;

	if (is_name(line))
	{
		ft_putendl("name");
		if (!is_valid_name(line))
			return (0);
	}
	else if (is_comment(line))
	{
		ft_putendl("comment");
		if (!is_valid_comment(line))
			return (0);
	}
	else if (is_label(line))
	{
		ft_putendl("label");
		if (!is_valid_label(line))
			return (0);
	}
	else
	{
		ft_putendl("ins");
		ins = ft_strsplit(line, ' ');
		if (!is_valid_mnemonic(ins[0]))
			return (0);
	}
	return (1);
}
