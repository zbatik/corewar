/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:39:32 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/24 15:51:14 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_name_main(t_input *head)
{
	t_input	*value;
	char	*tmp;

	value = head;
	while (value != NULL)
	{
		if (ft_strncmp(value->line, NAME_CMD_STRING, 5) == 0)
		{
			tmp = value->line + 5;
			while (ft_isws(*tmp))
				tmp++;
			ft_putchar('\t');
			putstr_ignore(tmp, '"');
			ft_putchar('\n');
			break ;
		}
		value = value->next;
	}
}

void	print_comment_main(t_input *head)
{
	t_input	*value;
	char	*tmp;

	value = head;
	while (value != NULL)
	{
		if (ft_strncmp(value->line, COMMENT_CMD_STRING, 8) == 0)
		{
			tmp = value->line + 8;
			while (ft_isws(*tmp))
				tmp++;
			ft_putchar('\t');
			putstr_ignore(tmp, '"');
			ft_putchar('\n');
			break ;
		}
		value = value->next;
	}
}

void	print_all(t_main *var, char *fname)
{
	ft_putstr("Assembling ");
	ft_putstr(fname);
	ft_putendl(":");
	print_name_main(var->input);
	print_comment_main(var->input);
	print_cor(var, fname);
}

void	begin_process(t_main *var, char *fname)
{
	store_input(var, fname);
	error_check_data(var);
	if (parse_listinfo(var) == TRUE)
		print_all(var, fname);
	else
		ft_putendl("ERROR: error in file");
	exit_function(var);
}

int		main(int ac, char *av[])
{
	t_main	var;
	int		i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (is_valid_filename(av[i], ".s"))
				begin_process(&var, av[i]);
			else
				ft_printf(2, na, "File %s is not a .s file\n", av[i]);
			i++;
		}
	}
	else
	{
		ft_printf(1, na, "Usage:\n./asm file_name(s)[.s] ...");
		return (0);
	}
	return (0);
}
