/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:54:11 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/21 16:47:56 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t len;
	size_t i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s) + 1;
	while (i < len)
	{
		if (*(s + i) == (char)c)
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
