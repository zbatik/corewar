/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:32:58 by emaune            #+#    #+#             */
/*   Updated: 2018/09/18 13:45:41 by emaune           ###   ########.fr       */
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

void				ft_printf(int fd, const char *control_string, ...);
char				*ft_itoa_base(int value, int base);
int					is_conversion_char(char c);

#endif
