/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_filename.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 14:55:54 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/26 14:56:18 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

int		is_valid_filename(char *s, char *extension)
{
	if (ft_strstr(s, extension) == NULL)
		return (FALSE);
	return (TRUE);
}
