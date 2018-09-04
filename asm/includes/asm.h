/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:29:35 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/04 13:29:36 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include <libft.h>

typedef struct	s_instruct
{
	
	t_opnum 	name;
	int 		args[MAX_ARGS];
	t_arg_type	type[MAX];
	char		

	data	*next;

}				t_instruct;

typedef struct	s_label
{
	char	*name;
	int		index;
	
}				t_label;
#endif

/**
indexing of labels starts from 256
*/
