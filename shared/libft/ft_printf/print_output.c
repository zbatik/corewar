/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 13:30:40 by emaune            #+#    #+#             */
/*   Updated: 2018/09/19 14:53:13 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_output(const char *s, t_var *var, int fd)
{
	int			i;

	i = 0;
	var->temp = var->conv;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (is_conversion_char(s[i]) && var->temp)
			{
				ft_putstr_fd(var->temp->str, fd);
				var->temp = var->temp->next;
			}
		}
		else
			ft_putchar_fd(s[i], fd);
		i++;
	}
}
