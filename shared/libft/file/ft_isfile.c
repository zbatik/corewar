/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 11:03:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/08/01 11:09:37 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_isfile(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd > 0)
	{
		return (1);
		close(fd);
	}
	else
		return (0);
}
