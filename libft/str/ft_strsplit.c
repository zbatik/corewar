/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:59:31 by zack              #+#    #+#             */
/*   Updated: 2018/06/12 14:41:41 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

static int	split_count(char const *s, char c)
{
	int count;

	count = *s != c;
	while (*s)
	{
		if (*s == c && *(s + 1) != c)
			count++;
		s++;
	}
	count = count - (*(s - 1) == c);
	return (count);
}

static int	split_len(char const *s, char c)
{
	int count;

	count = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != 0)
	{
		count++;
		s++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	split = (char**)malloc(sizeof(char*) * (split_count(s, c) + 1));
	if (!split)
		return (NULL);
	if (*s != c && *s != 0)
		split[i++] = ft_strsub(s, 0, split_len(s, c));
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != 0)
			split[i++] = ft_strsub(s + 1, 0, split_len(s, c));
		s++;
	}
	split[i] = 0;
	return (split);
}
