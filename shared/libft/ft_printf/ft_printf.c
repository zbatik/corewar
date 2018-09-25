/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 11:03:56 by emaune            #+#    #+#             */
/*   Updated: 2018/09/24 11:28:55 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				is_conversion_char(char c)
{
	int			i;

	i = 0;
	while (CONVERSION_CHARS[i])
	{
		if (CONVERSION_CHARS[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void			add_conversion(t_var *var, char c)
{
	if (!var->conv)
	{
		var->conv = (t_conv*)malloc(sizeof(t_conv));
		var->temp = var->conv;
		var->conv->c = c;
		var->conv->next = NULL;
		var->conv->prev = NULL;
	}
	else
	{
		var->temp->next = (t_conv*)malloc(sizeof(t_conv));
		var->temp->next->prev = var->temp;
		var->temp = var->temp->next;
		var->temp->c = c;
		var->temp->next = NULL;
	}
}

void			init_conv(t_var *var, const char *s)
{
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			if (is_conversion_char(s[i]))
				add_conversion(var, s[i]);
		}
		if (s[i])
			i++;
	}
}

void			store_args(t_var *var)
{
	var->temp = var->conv;
	while (var->temp)
	{
		if (var->temp->c == 'd')
		{
			var->n = va_arg(var->args, int);
			var->temp->str = ft_itoa(var->n);
		}
		if (var->temp->c == 's')
		{
			var->s = va_arg(var->args, char *);
			var->temp->str = ft_strdup(var->s);
		}
		if (var->temp->c == 'x')
		{
			var->n = va_arg(var->args, int);
			var->temp->str = ft_itoa_base(var->n, 16);
		}
		var->temp = var->temp->next;
	}
}

void			ft_printf(int fd, t_colour c,  const char *control_string, ...)
{
	t_var		var;

	var.conv = NULL;
	va_start(var.args, control_string);
	init_conv(&var, control_string);
	store_args(&var);
	va_end(var.args);
	ft_putstr(select_colour(c));
	print_output(control_string, &var, fd);
//	free_conv(var.conv);
	ft_putstr("\x1b[0m");
}
