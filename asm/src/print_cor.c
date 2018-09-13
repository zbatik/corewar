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
//	(void) tmp;
//	(void) i;
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
				printf("%x ",*tmp->byte_code[0]);
				//(void) j;
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
