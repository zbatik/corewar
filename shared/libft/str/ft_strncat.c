/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:22:45 by zbatik            #+#    #+#             */
/*   Updated: 2018/05/31 11:54:00 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = s1;
	while (*tmp)
		tmp++;
	while (*s2 && i < n)
	{
		*tmp = *s2;
		s2++;
		tmp++;
		i++;
	}
	*tmp = 0;
	return (s1);
}
