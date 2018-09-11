/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:35:14 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/11 12:35:15 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_input	*get_label(t_input *head, const char *str)
{
	t_input	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->is_label == TRUE)
		{
			if (ft_strncmp(str, tmp->line, ft_strlen(str)) == 0)
				return (tmp);
			tmp = tmp->next;
		}
	}
	return (NULL);
}
