/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_cl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:11:05 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/17 17:01:54 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_cl(char *s, t_colour colour)
{
	ft_putstr(select_colour(colour));
	ft_putstr(s);
	ft_putendl(SWTCH(colour));
}
