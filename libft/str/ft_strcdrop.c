/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdrop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:46:23 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/22 11:53:17 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcdrop(char const *str, char c)
{
	char	*drop;
	int		ind;

	ind = ft_indexcin(str, c);
	if (ind < 0)
		drop = ft_strnew(0);
	else
		drop = ft_strdrop(str, ind + 1);
	return (drop);
}
