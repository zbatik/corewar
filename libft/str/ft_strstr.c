/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 10:47:21 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/10 14:39:01 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_match(const char *haystack, const char *needle, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	int lenn;
	int lenh;
	int i;

	i = 0;
	lenn = ft_strlen(needle);
	lenh = ft_strlen(haystack);
	if (!*needle)
		return ((char*)haystack);
	while (i < 1 + lenh - lenn)
	{
		if (ft_match(haystack, needle, lenn))
			return ((char*)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
