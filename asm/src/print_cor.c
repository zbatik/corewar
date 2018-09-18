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
** Take the fname and change it to .cor
** Find if theres a name and comment section write those first
** Write everything else that is in byte_code in the head
**
*/

void	str_to_unstr(unsigned char *arr, char *str, int size)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < size)
	{
		if (str[i] != '"')
			arr[i] = (unsigned char) str[i];
		else
			arr[i] = 0;
		i++;
	}
	while (i < size)
		arr[i++] = 0;
}

void	print_name(t_input *head, int fd)
{
	t_input *tmp;
	char	*in;
	unsigned char	out[PROG_NAME_LENGTH];
	int		i;
	int		j;

	tmp = head;
	while (tmp != NULL)
	{
		in = tmp->line;
		while(ft_isws(*in) == TRUE)
			in++;
		if (ft_strncmp(in, NAME_CMD_STRING, 5) == 0)
		{
			in = in + 5;
			while(ft_isws(*in) == TRUE)
				in++;
			str_to_unstr(out, in, PROG_NAME_LENGTH);
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		ft_memset(&out, 0, PROG_NAME_LENGTH);
	i = 0;
	j = 0;
	while (i < PROG_NAME_LENGTH)
	{
		if (i % 2 == 0)
		{
			if (j == 7)
			{
				j = 0;
				printf("\n");
			}
			else
			{
				j++;
				printf(" ");
			}
		}
		write(1, &out[i], sizeof(unsigned char));
		printf("%02x", out[i++]);
	}
}
void	print_magic(int fd)
{
	unsigned int	x;

	x = COREWAR_EXEC_MAGIC;
	if (fd > 0)
	{
		write(fd, &x, sizeof(unsigned int));
	}
	printf("%02x", x);
}

void	print_comment(t_input *head, int fd)
{
	t_input *tmp;
	char	*in;
	unsigned char	out[COMMENT_LENGTH];
	int		i;
	int		j;

	tmp = head;
	while (tmp != NULL)
	{
		in = tmp->line;
		while(ft_isws(*in) == TRUE)
			in++;
		if (ft_strncmp(in, COMMENT_CMD_STRING, 8) == 0)
		{
			in = in + 8;
			while(ft_isws(*in) == TRUE)
				in++;
			str_to_unstr(out, in, COMMENT_LENGTH);
			break;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		ft_memset(&out, 0, COMMENT_LENGTH);
	i = 0;
	j = 0;
	while (i < COMMENT_LENGTH)
	{
		if (i % 2 == 0)
		{
			if (j == 7)
			{
				j = 0;
				printf("\n");
			}
			else
			{
				j++;
				printf(" ");
			}
		}
		printf("%02x", out[i]);
		write(fd, &out[i++], sizeof(unsigned char));
	}
}

void	print_cor(t_input *head, char *fname)
{
	int	fd;
	t_input	*tmp;
	int	i;
	int	j;
	static int	count = 1;
	static int	count2 = 0;
	int max;
	char	*new_name;

	tmp =  head;
	new_name = ft_strsub(fname, 0, ft_indexcin(fname, '.'));
	swapnfree(&new_name, ft_strjoin(new_name, ".cor"));
	fd = open (new_name, O_RDWR | O_CREAT, 0777);
	print_magic(fd);
	print_name(head, fd);
	print_comment(head, fd);
	while (tmp != NULL)
	{
		if (is_wsstring(tmp->line) == FALSE)
		{
			i = 0;
			if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
				&& is_comment(tmp->line) == FALSE)
			{	
				if (count % 1 == 0)
				{
					if (count2 == 16)
					{
						count2 = 0;
						printf("\n");
					}
					else
					{
						count2++;
						printf(" ");
					}
				}
				printf("%02x",tmp->byte_code[0][0]);
				write(fd, &tmp->byte_code[0][0], sizeof(unsigned char));
				count++;
				if (tmp->param_encoding != 0)
				{
					if (count % 1 == 0)
					{
						if (count2 == 16)
						{
							count2 = 0;
							printf("\n");
						}
						else
						{
							count2++;
							printf(" ");
						}
					}
					printf("%02x", tmp->param_encoding);
					write(fd, &tmp->param_encoding, sizeof(unsigned char));
					count++;
				}
				while (tmp->args[i] != '\0')
				{
					j = 0;
					if (tmp->args[i] == 'I')
						max = IND_SIZE;
					else if (tmp->args[i] == 'D')
						max = DIR_SIZE;
					else if (tmp->args[i] == 'd')
						max = ASM_DIR;
					else
						max = REG_SIZE;
					while (j  < max)
					{
						if (count % 1 == 0)
						{
							if (count2 == 16)
							{
								count2 = 0;
								printf("\n");
							}
							else
							{
								count2++;
								printf(" ");
							}
						}
						printf("%02x", tmp->byte_code[i + 1][j]);
						write(fd, &tmp->byte_code[i + 1][j++], sizeof(unsigned char));
						count++;
					}
					i++;
				}
			}
		//	printf("Byte size of this instruction: %d\n",tmp->byte_count);
		}

		tmp = tmp->next;
	}
	close (fd);
}
