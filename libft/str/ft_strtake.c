/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:49:12 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/21 17:13:13 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtake(char const *str, size_t n)
{
	char	*take;
	int		len;
	int		m;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	m = ft_min(n, len);
	take = ft_strsub(str, 0, m);
	if (take == NULL)
		return (NULL);
	return (take);
}
