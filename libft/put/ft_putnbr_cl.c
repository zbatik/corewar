/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_cl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:11:05 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/17 17:02:06 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_cl(int n, t_colour colour)
{
	ft_putstr(select_colour(colour));
	ft_putnbr(n);
	ft_putstr(SWTCH(colour));
}
