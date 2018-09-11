/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 11:31:03 by mdilapi           #+#    #+#             */
/*   Updated: 2018/05/03 11:31:04 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void recursive_putnum(int n, char *s, int base, int count)
{
	if (n > base - 1)
		recursive_putnum(n/base, s, base, count + 1);
	s[count] = n % base + '0';
	if (n > 9 && base > 10)
	{
		s[count] = s[count] - '0' + 'W';
	} 
}
void	reverse_str(char *s, int len,int is_minus)
{
	int i;
	int j;
	char tmp;

	if (is_minus == 1)
		i = 1;
	else i = 0;
	j = len - 1;

	while (i < (len/2))
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		j--;
		i++;
	}
}

char	*ft_itoa_base(int value, int base)
{
	int count;
	int tmp;
	char* ret;
	int set_minus;

	ret = 0;
	set_minus = 0;
	if (base <= 16 && base >= 2)
	{
		count = 0;
		tmp = value;
		if (tmp < 0)
		{
			if (base == 10)
			{
				set_minus = 1;
			}
			tmp *= -1;
			value *= -1;
		}
		while (tmp > 0)
		{
			tmp /= base;
			count++;
		}
		if (set_minus == 1)
			count ++;
		ret = (char *)malloc(sizeof(char) * count + 1);
		if(set_minus == 1)
		{
			recursive_putnum(value, ret, base, 1);
			ret[0] = '-';
		}
		else recursive_putnum(value, ret, base, 0);
		reverse_str(ret, count, set_minus);
		ret[count + 1] = '\0';

	}
	return (ret);
}
