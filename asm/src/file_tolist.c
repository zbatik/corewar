/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tolist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:24:31 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/24 16:08:32 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		is_wsstring(const char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
			if (ft_isws(str[i++]) == 0)
				return (FALSE);
	}
	return (TRUE);
}

int		arg_byte_count(char *str)
{
	int		ret;
	char	*tmp;

	ret = 0;
	tmp = str;
	while (*tmp != '\0')
	{
		if (*tmp == 'I')
			ret += IND_SIZE;
		else if (*tmp == 'R')
			ret += ASM_REG;
		else if (*tmp == 'd')
			ret += ASM_DIR;
		else
			ret += DIR_SIZE;
		tmp++;
	}
	return (ret);
}
