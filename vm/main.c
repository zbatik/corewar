/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 13:43:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/02 14:51:28 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inter.h"
/*
int	strtohex(char *hex)
{
	char	*hexstr;
	int		n;

	hexstr = "0123456789abcdef";
	if (ft_strlen(hex) != 2)
	{
		ft_puterror("Invaild hex input");
		exit(-1);
	}
	n = ft_indexcin(hex[0], e
	
}
*/
int main(void)
{
	unsigned int         number;
	int			start_reg;
	int			exec_reg;
	int			player_len;
	t_byte		reg[MEM_SIZE];
	char		colouring[MEM_SIZE];

	ft_bzero(reg, MEM_SIZE);
	ft_bzero(colouring, MEM_SIZE);
	ft_putendl_cl("Initialised Battle Field Memory", c);
	
	ft_putendl("Enter player starting regester:");
	scanf("%d", &start_reg);

	ft_putendl("Enter player length:");
	scanf("%d", &player_len);
	
	ft_putendl_cl("Enter player one byte at a time and then Cnt D:", c);
	int i = -1;
	while (++i < player_len) 
	{
		scanf("%x", &number);
		reg[start_reg % MEM_SIZE] = number;
		colouring[start_reg % MEM_SIZE] = g;
		start_reg++;
	}
	
	ft_putendl("Enter player regester to execute:");
	scanf("%d", &exec_reg);
	
	ft_putendl("View Core [y = 1/n = 0]");
	int yn;
	scanf("%d", &yn);
	if (yn == 1)
		print_mem(reg, colouring);
}
