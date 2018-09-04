/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:48:00 by zbatik            #+#    #+#             */
/*   Updated: 2018/06/11 11:41:40 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	trim_len(char const *s, int len)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (ft_isws(s[i++]))
		count++;
	i = len - 1;
	while (ft_isws(s[i--]) && i > 0)
		count++;
	return (len - ft_min(count, len));
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		n;
	int		len;
	char	*trim;

	if (s == NULL)
		return (NULL);
	len = trim_len(s, ft_strlen(s));
	trim = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	i = 0;
	n = 0;
	while (ft_isws(s[i]))
		i++;
	while (n < len)
	{
		trim[n] = s[i];
		n++;
		i++;
	}
	trim[n] = 0;
	return (trim);
}
