/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:29:35 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/05 18:27:31 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "../../shared/includes/shared.h"

# define DEBUG 1

/*
*/

/*
typedef struct	s_instruct
{
	
	t_opnum 	name;
	int 		args[MAX_ARGS_NUMBER];
	t_arg_type	type[MAX_ARGS_NUMBER];
	t_byte		*instruct_byte_code;		
	t_instruct	*next;

}				t_instruct;
*/
/*
** Zack's fns
*/

t_opnum inst_to_enum(char *str);
t_opinfo	index_opinfo(t_opnum op_index);
int instruction_byte_size(t_byte *instuction_line);

/*
** Eddie's fns
*/

/*
** Fred's fns
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
