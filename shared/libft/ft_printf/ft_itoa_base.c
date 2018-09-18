/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 09:02:31 by exam              #+#    #+#             */
/*   Updated: 2018/09/18 13:07:05 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_itoa_base(int value, int base)
{
	char	*str;
	long	n;
	int		sign;
	int		i;

	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	str = (char*)malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		str[i] = n % base < 10 ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	str[i] = i == 0 ? '-' : 0;
	return (str);
}
