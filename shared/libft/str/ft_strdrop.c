/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdrop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:39:50 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/21 18:42:53 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdrop(char const *str, size_t n)
{
	char *ret;

	if (str == NULL)
		return (NULL);
	ret = ft_strdup(str + ft_min(n, ft_strlen(str) + 1));
	if (ret == NULL)
		return (NULL);
	return (ret);
}
