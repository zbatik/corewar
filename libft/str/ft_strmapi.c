/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zack <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:27:58 by zack              #+#    #+#             */
/*   Updated: 2018/06/12 14:42:16 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	map = ft_strnew(len);
	if (!map)
		return (NULL);
	i = 0;
	while (s[i])
	{
		map[i] = f(i, s[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}
