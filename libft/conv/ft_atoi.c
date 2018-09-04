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

static int	is_vaild(const char *c)
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

static int	ft_ctoi(char n)
{
	return (n - '0');
}

int			ft_atoi(const char *str)
{
	long sign;
	long n;

	sign = 1;
	n = 0;
	while ((!ft_isdigit(*str)) && *str != '-')
	{
		if (!is_vaild(str))
			return (0);
		str++;
	}
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		n *= 10;
		n += ft_ctoi(*str);
		str++;
	}
	return (n * sign);
}
