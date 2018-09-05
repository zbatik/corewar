/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:47:42 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/03 16:43:43 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*ss;
	size_t			i;
	unsigned char	cc;

	i = 0;
	ss = (char*)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if ((unsigned char)*ss == cc)
			return (ss);
		i++;
		ss++;
	}
	return (NULL);
}
