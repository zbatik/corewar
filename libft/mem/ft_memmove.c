/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:13:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/03 16:39:48 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*srccpy;
	char		*dstcpy;

	dstcpy = dst;
	srccpy = src;
	i = n;
	while (i >= 1)
	{
		dstcpy[i - 1] = srccpy[i - 1];
		i--;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		return (ft_memrcpy(dst, src, len));
	else if (src > dst)
		return (ft_memcpy(dst, src, len));
	return (dst);
}
