/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctake.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:47:55 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/22 12:44:16 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strctake(char const *str, char c)
{
	char	*take;
	int		ind;

	ind = ft_indexcin(str, c);
	if (ind < 0)
		take = ft_strdup(str);
	else
		take = ft_strtake(str, ind);
	return (take);
}
