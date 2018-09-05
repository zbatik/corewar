/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 13:31:47 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/22 14:38:48 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1
# define MIN_INT (-MI - 1)
# define MI 2147483647

# include "libft.h"

int	get_next_line(const int fd, char **line);
int skip_lines(const int fd, int skip);
int ft_isfile(char *file);

#endif
