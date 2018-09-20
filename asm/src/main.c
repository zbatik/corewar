/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 14:39:32 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/18 13:51:42 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>

/*TODO
**At the end of the main process delete memory
** input_del needs to be tested
** After file_tolist all error handling (is_validfile)
** Upadate byte count will require pass_param function
** After Error handling we need to run function that
** 			popuates the input with byte_size instuction_code etc 
**	Write to file which will take all the info in in_head and print its bytes
*/

void	putstr_ignore(const char *str, char c)
{
	char	*tmp;

	tmp = (char *)str;
	while (*tmp != '\0')
	{
		if (*tmp != c)
			write(1, &*tmp, 1);
		tmp++;
	}
}

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
/** TODO
** Code the exit function
**
*/
int 	main(int ac, char *av[])
{
	t_main var;

	if (ac > 1)
	{
		store_input(&var, av[1]);
		error_check_data(&var);
		if (parse_listinfo(&var) == TRUE)
		{
			ft_putstr("Assembling ");
			ft_putstr(av[1]);
			ft_putendl(":");
			print_name_main(var.input);
			print_comment_main(var.input);
			print_cor(&var, av[1]);
		}
		else
			ft_putendl("ERROR: error in file");
	}
	else
	{
		ft_printf(1, "Usage:\n./asm file_name[.s] ...");
		return (0);
	}
	//exit_function(&var);
	return (0);
}
