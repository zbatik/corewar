/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:22:45 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/05 11:34:55 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t lens;
	size_t lend;

	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (dstsize < lend + 1)
		return (lens + dstsize);
	ft_strncat(dst, src, dstsize - (lend + 1));
	return (lend + lens);
}
