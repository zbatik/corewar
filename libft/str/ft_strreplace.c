/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 17:14:16 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/22 17:38:12 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strreplace(char **replace, char *with)
{
	if (replace == NULL || with == NULL)
		return (NULL);
	if (*replace != NULL)
		free(*replace);
	*replace = with;
	return (*replace);
}
