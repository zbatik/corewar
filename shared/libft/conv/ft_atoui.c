/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atio.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 21:03:06 by zack              #+#    #+#             */
/*   Updated: 2018/06/05 13:45:06 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
int	is_vaild(const char *c)
{
	if (*c == 0)
		return (0);
	if (*c == '+')
	{
		if (!ft_isdigit(*(c + 1)))
			return (0);
	}
	else if (!ft_isws(*c))
		return (0);
	return (1);
}

int	ft_ctoi(char n)
{
	return (n - '0');
}

unsigned int			ft_atoui(const char *str)
{
	unsigned int n;

	n = 0;
	while ((!ft_isdigit(*str)) && *str != '-')
	{
		if (!is_vaild(str))
			return (0);
		str++;
	}
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		n *= 10;
		n += ft_ctoi(*str);
		str++;
	}
	return (n);
}
