/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:05:17 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/03 14:56:10 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t					i;
	const unsigned char		*srccpy;
	unsigned char			*dstcpy;
	unsigned char			cc;

	cc = (unsigned char)c;
	dstcpy = (unsigned char*)dst;
	srccpy = (const unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dstcpy[i] = srccpy[i];
		if (srccpy[i] == cc)
		{
			return (dstcpy + (i + 1));
		}
		i++;
	}
	return (NULL);
}
