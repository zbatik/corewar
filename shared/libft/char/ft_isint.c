/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:25:27 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/07 14:26:11 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isint(char *in)
{
	int		len;
	char	str_int[11];
	int		sign;
	int		i;

	sign = 0;
	if (*in == '-')
		sign = 1;
	ft_strcpy(str_int, "2147483647");
	str_int[9] += sign;
	len = ft_strlen(in + sign);
	if (len > 10)
		return (0);
	if (len < 10)
		return (1);
	i = sign - 1;
	while (in[++i])
	{
		if (in[i] > str_int[i - sign])
			return (0);
	}
	return (1);
}