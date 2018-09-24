/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:08:16 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/07 11:08:17 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <stdio.h>


/**TODO
** Nothing
*/

void	str_to_str(char *arr, char *str, int size)
{
	int	i;

	i = 0;
	while (*str != '\0' && i < size)
	{
		if (*str != '"')
			arr[i++] = (char) *str++;
		else
			str++;
	}
	while (i < size)
		arr[i++] = 0;
}

void	print_name(header_t *header, t_input *head)
{
	t_input *tmp;
	char	*in;
	int		set;

	tmp = head;
	set = 0;
	while (tmp != NULL && set == 0)
	{
		in = tmp->line;
		while(ft_isws(*in) == TRUE)
			in++;
		if (ft_strncmp(in, NAME_CMD_STRING, 5) == 0)
		{
			in = in + 5;
			while(ft_isws(*in) == TRUE)
				in++;
			str_to_str(header->prog_name, in, PROG_NAME_LENGTH);
			header->prog_name[PROG_NAME_LENGTH] = '\0';
			set = 1;
		}
		tmp = tmp->next;
	}
	if (set == 0)
		ft_memset(&header->prog_name, 0, PROG_NAME_LENGTH + 1);
}

void	print_comment(header_t *header, t_input *head)
{
	t_input *tmp;
	char	*in;
	int		set;

	tmp = head;
	set = 0;
	while (tmp != NULL && set == 0)
	{
		in = tmp->line;
		while(ft_isws(*in) == TRUE)
			in++;
		if (ft_strncmp(in, COMMENT_CMD_STRING, 8) == 0)
		{
			in = in + 8;
			while(ft_isws(*in) == TRUE)
				in++;
			str_to_str(header->comment, in, COMMENT_LENGTH);
			header->comment[COMMENT_LENGTH] = '\0';
			set = 1;
		}
		tmp = tmp->next;
	}
	if (set == 0)
		ft_memset(&header->comment, 0, COMMENT_LENGTH + 1);
}

int		get_size(char arg)
{
	if (arg == 'I')
		return (IND_SIZE);
	else if (arg == 'D')
		return (DIR_SIZE);
	else if (arg == 'd')
		return (ASM_DIR);
	else
		return (ASM_REG);
	return (0);
}

void	print_rest(t_input *tmp, int fd)
{
	int	i;
	int	j;

	while (tmp != NULL)
	{
		if (is_wsstring(tmp->line) == FALSE)
		{
			i = 0;
			if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
				&& is_comment(tmp->line) == FALSE)
			{	
				write(fd, &tmp->byte_code[0][0], sizeof(unsigned char));
				if (tmp->param_encoding != 0)
					write(fd, &tmp->param_encoding, sizeof(unsigned char));
				while (tmp->args[i] != '\0')
				{
					j = 0;
					while (j  < get_size(tmp->args[i]))
						write(fd, &tmp->byte_code[i + 1][j++], sizeof(unsigned char));
					i++;
				}
			}
		}
		tmp = tmp->next;
	}
}

void	print_cor(t_main *var, char *fname)
{
	int	fd;
	char	*new_name;
	header_t	header;

	new_name = ft_strsub(fname, 0, ft_indexrcin(fname, '.'));
	swapnfree(&new_name, ft_strjoin(new_name, ".cor"));
	fd = open (new_name, O_RDWR | O_CREAT);
	chmod(new_name, 0777);
	header.magic = COREWAR_EXEC_MAGIC;
	header.magic = rev_endian(header.magic);
	print_name(&header, var->input);
	var->total_player_size = rev_endian(var->total_player_size);
	header.prog_size = var->total_player_size;
	print_comment(&header, var->input);
	write(fd, &header, sizeof(header_t));
	print_rest(var->input, fd);
	close (fd);
	free(new_name);
}
