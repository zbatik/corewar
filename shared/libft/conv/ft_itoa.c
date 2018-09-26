/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:28:06 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/12 15:43:15 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_nbrlen(long n)
{
	int count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char		*ft_itoa(int n)
{
	long	l;
	int		i;
	int		len;
	char	*nbr;

	l = (long)n;
	len = ft_nbrlen(n);
	nbr = ft_strnew(len);
	if (!nbr)
		return (NULL);
	i = len - 1;
	nbr[len] = 0;
	if (l < 0)
	{
		nbr[0] = '-';
		l = -l;
	}
	while (i >= (0 + (nbr[0] == '-')))
	{
		nbr[i] = 48 + l % 10;
		l = l / 10;
		i--;
	}
	return (nbr);
}
