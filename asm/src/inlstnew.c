/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inlstnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:07:55 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/07 14:07:56 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_input	*inlstnew(char	*line, int line_no, t_bool is_label)
{
	t_input	*ret;

	if ((ret = (t_input *)malloc(sizeof(t_input))) == NULL)
		return (NULL);
	ret->line = ft_strdup(line);
	ret->line_no = line_no;
	ret->is_label = is_label;
	return (ret);
}
