/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:29:35 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/05 10:31:55 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "../libft/includes/libft.h"

typedef unsigned char	t_byte;

typedef struct	s_instruct
{
	
	t_opnum 	name;
	int 		args[MAX_ARGS];
	t_arg_type	type[MAX];
	char		

	data	*next;

}				t_instruct;

/*
** lable list can be replaced with a libft t_list
*/

/*
typedef struct	s_label
{
	char	*name;
	int		index;
	
}				t_label;
*/
#endif

/**
indexing of labels starts from 256
*/
