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

/**TODO
** Take the fname and change it to .cor
** Find if theres a name and comment section write those first
** Write everything else that is in byte_code in the head
**
*/


void	print_hex(int num)
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
	int	count;

	tmp =  head;
	fd = 1;
	(void) fd;
	(void) fname;
	count  = 0;
	while (tmp != NULL)
	{
		i = 0;
		if (is_label(tmp->line) == FALSE && is_name(tmp->line) == FALSE
			&& is_comment(tmp->line) == FALSE)
		{
			while (i < tmp->byte_count)
			{
				if ((int )tmp->byte_code[i] < 16)
					write(1, "0", 1);
				print_hex((int )tmp->byte_code[i++]);
				if (i % 2 == 0)
				{
					ft_putchar(' ');
					count++;
				}
				if (count == 8)
				{
					write(1, "\n", 1);
					count = 0;
				}
			}

		}

		tmp = tmp->next;
	}
}
