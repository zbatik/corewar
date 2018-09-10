/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaune <emaune@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 13:28:12 by emaune            #+#    #+#             */
/*   Updated: 2018/09/09 16:15:16 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int		line_has_label(char *line)
{
	int			i;

	i = 0;
	if (!ft_strchr(line, ':'))
		return (0);
	while (line[i])
	{
		if (line[i] == ':')
		{
			if (i > 0)
			{
				if (line[i - 1] == ' ' || line[i - 1] == '%')
					return (0);	
			}
			break ;
		}
		i++;
	}
	return (1);
}

static int		line_has_label_only(char *line)
{
	char		*s;

	s = ft_strchr(line, ':');
	if (s)
	{
		s++;
		if (!*s)
			return (1);
		while (*s)
		{
			if (*s != ' ' && *s != '\t')
				return (0);
			s++;
		}
	}
	return (1);
}

static void     add_line(t_main *var, char *line, int is_split)
{
	if (!var->input)
	{ 
		var->input = (t_input*)malloc(sizeof(t_input));
		var->input->line = ft_strtrim(line);
		var->input->line_no = 1;
		var->input->next = NULL;
		var->input->prev = NULL;
		var->temp_input = var->input;
	}
	else
	{
		var->temp_input->next = (t_input*)malloc(sizeof(t_input));
		var->temp_input->next->prev = var->temp_input;
		var->temp_input = var->temp_input->next;
		if (!is_split)
			var->temp_input->line_no = var->temp_input->prev->line_no + 1;
		else
			var->temp_input->line_no = var->temp_input->prev->line_no;
		var->temp_input->line = ft_strtrim(line);
		var->temp_input->next = NULL;
	}
}

static void		split_and_add(t_main *var, char *line)
{
	char		*s;
	char		c;

	s = ft_strchr(line, ':') + 1;
	c = *s;
	*s = '\0';
	add_line(var, line, 0);
	*s = c;
	while (*s == ' ' || *s == '\t')
		s++;
	if (ft_isprint(*s))
		add_line(var, s, 1);

}


void            store_input(t_main *var, char *fname)
{
	int         fd;
	//int         i;
	char        *line;

	fd = open(fname, O_RDONLY);
	//i = 1;
	var->input = NULL;
	if (fd < 0)
	{
		ft_putendl("Error: Cannot open file.");
		exit(EXIT_FAILURE);
	}
	while (get_next_line(fd, &line) > 0)
	{
		if (is_wsstring(line) == FALSE)
		{
			if (line_has_label(line) && !line_has_label_only(line))
				split_and_add(var, line);
			else
				add_line(var, line, 0);
			if(is_label(var->temp_input->line) ==  TRUE)
				var->temp_input->is_label = TRUE;
		}
		ft_strdel(&line);
	}
	var->temp_input = var->input;
}
