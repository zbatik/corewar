/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_tolist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 10:24:31 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/07 10:24:33 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>
/* TODO: 
**convert the file to a linked list with each lines
**check forbidden characters
**if the start of the line is a label, followed by commands make a split
** split this function up into a smaller collection
** Check if the characters are legit
** trim whitespaces before and after the input string && swap out tabs for spaces
*/

void	process_normal(char *str, t_input **tmp, int *i)
{
	if (tmp!= NULL && *tmp != NULL && str != NULL)
	{
		tmp[0]->line = ft_strdup(str);
		tmp[0]->line_no = *i;
		*i = *i + 1;
		//free(str);
		tmp[0]->next = NULL;
		//tmp[0]->next = (t_input *)malloc(sizeof(t_input));
	}
}

void	process_label(char **label, t_input **tmp, int *i)
{
		tmp[0]->line = *label;
		tmp[0]->is_label = TRUE;
		tmp[0]->line_no = *i;
		*i = *i + 1;
		//free(label);
		tmp[0]->next = NULL;
		//tmp[0]->next = (t_input *)malloc(sizeof(t_input));
}

int		is_wsstring(const char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
			if (ft_isws(str[i++]) == 0)
				return (FALSE);
	}
	return (TRUE);
}

void	init_head(int fd, t_input *head)
{
	if (get_next_line(fd, &str) < 0)
	{
		ft_putendl("ERROR: Cant read from file");
		return (NULL);
	}
	
}

t_input	*file_tolist(char *fname)
{
	int		fd;
	t_input	*head;
	t_input	*tmp;
	char	*str;
	char	*label;
	int		i;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("ERROR: File does not exist");
		return (NULL);
	}
	i = 1;
	while (get_next_line(fd, &str) > 0)
	{
		if (is_wsstring(str) == FALSE)
		{
			if (ft_indexcin(str, ':') != -1)
			{
				label = ft_strsub(str, 0, ft_indexcin(str, ':'));
				if (is_valid_label(label) == TRUE)
				{
					process_label(&label, &tmp, &i);
					process_normal(str + ft_indexcin(str, ':')+ 1, &tmp, &i);
					tmp = tmp->next;
				}
				else
				{
					process_normal(str, &tmp, &i);
					tmp = tmp->next;
				}
			}
			else
			{
				process_normal(str, &tmp, &i);
				tmp = tmp->next;
			}
		}
	}
	//tmp->next = NULL;
	close(fd);
	return (head);
}
