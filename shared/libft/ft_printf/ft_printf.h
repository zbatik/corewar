/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:32:58 by emaune            #+#    #+#             */
/*   Updated: 2018/09/19 14:38:54 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

# define CONVERSION_CHARS "dsx"

typedef struct		s_conv
{
	char			c;
	char			*str;
	struct s_conv	*next;
	struct s_conv	*prev;
}					t_conv;

typedef struct		s_var
{
	t_conv			*conv;
	t_conv			*temp;
	int				n;
	char			*s;
	va_list			args;
}					t_var;

void				ft_printf(int fd, t_colour c,
		const char *control_string, ...);
char				*ft_itoa_base(int value, int base);
int					is_conversion_char(char c);
void				print_output(const char *s, t_var *var, int fd);
void				free_conv(t_conv *c);

#endif
