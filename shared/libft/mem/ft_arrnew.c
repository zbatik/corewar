/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:54:42 by zbatik            #+#    #+#             */
/*   Updated: 2018/07/13 12:07:20 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_arrnew(size_t x, size_t y)
{
	char	**arr;
	size_t	i;

	arr = (char**)ft_memalloc(sizeof(char*) * (x + 1));
	i = 0;
	while (i < x)
		arr[i++] = ft_strnew(y);
	arr[i] = NULL;
	return (arr);
}
