/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:51:40 by zbatik            #+#    #+#             */
/*   Updated: 2018/05/30 17:12:56 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*upd;

	upd = (unsigned char*)b;
	i = 0;
	while (i < len)
	{
		*upd = (unsigned char)c;
		upd++;
		i++;
	}
	return (b);
}
