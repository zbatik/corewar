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


void	print_hex(unsigned int num)
{
	char	c;

	if(num > 15)
		print_hex(num / 16);
	if (num > 9)
		c = num + 'W';
	else
		c = num  + '0';
	write(1, &c, 1);
}

void	str_to_unstr(unsigned char *arr, char *str, int size)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < size)
	{
		arr[i] = (unsigned char) str[i];
		i++;
	}
	while (i < size)
		arr[i++] = 0;
}

void	print_name(t_input *head)
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
			//printf("I found a name in str: %s", in);
			in = in + 5;
			while(ft_isws(*in) == TRUE)
				in++;
			str_to_unstr(out, in, PROG_NAME_LENGTH);
			//printf("the unsinged str is :%s\n",out);
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
		printf("%x", out[i++]);
	}
}

void	print_comment(t_input *head)
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
			//printf("I found a comment in str: %s", in);
			in = in + 8;
			while(ft_isws(*in) == TRUE)
				in++;
			str_to_unstr(out, in, COMMENT_LENGTH);
			//printf("the unsinged str is :%s\n",out);
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
		printf("%x", out[i++]);
	}
}

void	print_cor(t_input *head, char *fname)
{
	int	fd;
	t_input	*tmp;
	int	i;
	int	j;
	int	count;
	int max;

	tmp =  head;
	fd = 1;
	(void) fd;
	(void) fname;
	count  = 0;
	(void) count;
	print_name(head);
	print_comment(head);
	while (tmp != NULL)
	{
		if (is_wsstring(tmp->line) == FALSE)
		{
			i = 0;
			if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
				&& is_comment(tmp->line) == FALSE)
			{	
				//print_hex(tmp->byte_code[0][1]);
				//print_hex(tmp->byte_code[0][0]);
				printf("%x",tmp->byte_code[0][0]);
				while (tmp->args[i] != '\0')
				{
					j = 0;
					if (tmp->args[i] == 'I')
						max = IND_SIZE;
					else if (tmp->args[i] == 'D')
						max = DIR_SIZE;
					else
						max = REG_SIZE;
					while (j  < max)
						printf("%x ", tmp->byte_code[i + 1][j++]);
					i++;
				}
				printf("\n");
			}
		}
		tmp = tmp->next;
	}
}
