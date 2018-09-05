/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:47:21 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/12 14:26:10 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t lenn;
	size_t lenh;
	size_t i;

	i = 0;
	lenn = ft_strlen(need);
	lenh = ft_strlen(hay);
	if (len == 0 || len < lenn)
		return (NULL);
	if (!*need)
		return ((char*)hay);
	if (lenh < lenn)
		return (NULL);
	while (i < 1 + ft_min(len, lenh) - lenn)
	{
		if (0 == ft_strncmp(hay, need, lenn))
			return ((char*)hay);
		hay++;
		i++;
	}
	return (NULL);
}
