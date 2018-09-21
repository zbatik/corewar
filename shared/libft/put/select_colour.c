/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_colour.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:34:59 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/19 14:13:53 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/colour.h"

char	*select_colour(t_colour colour)
{
	if (colour == r)
		return (ANSI_COLOUR_RED);
	else if (colour == g)
		return (ANSI_COLOUR_GREEN);
	else if (colour == y)
		return (ANSI_COLOUR_YELLOW);
	else if (colour == b)
		return (ANSI_COLOUR_BLUE);
	else if (colour == m)
		return (ANSI_COLOUR_MAGENTA);
	else if (colour == c)
		return (ANSI_COLOUR_CYAN);
	else if (colour == lr)
		return (ANSI_COLOUR_LIGHTRED);
	else
		return ("");
}
