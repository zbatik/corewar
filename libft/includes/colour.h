/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:08:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/02 13:54:10 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOUR_H
# define COLOUR_H

# define ANSI_COLOUR_RED     "\x1b[31m"
# define ANSI_COLOUR_GREEN   "\x1b[32m"
# define ANSI_COLOUR_YELLOW  "\x1b[33m"
# define ANSI_COLOUR_BLUE    "\x1b[34m"
# define ANSI_COLOUR_MAGENTA "\x1b[35m"
# define ANSI_COLOUR_CYAN    "\x1b[36m"
# define ANSI_COLOUR_RESET   "\x1b[0m"

# define SWTCH(x) (x == na ? "" : ANSI_COLOUR_RESET)

typedef enum
{
	na,
	r,
	g,
	y,
	b,
	m,
	c,
}	t_colour;

char	*select_colour(t_colour colour);
void	ft_putchar_cl(char c, t_colour colour);
void	ft_putstr_cl(char *s, t_colour colour);
void	ft_putendl_cl(char *s, t_colour colour);
void	ft_putnbr_cl(int n, t_colour colour);

#endif
