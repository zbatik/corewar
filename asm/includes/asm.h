/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:29:35 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/06 15:23:32 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../shared/includes/shared.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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

t_opnum				inst_to_enum(char *str);
t_opinfo			index_opinfo(t_opnum op_index);
int					instruction_byte_size(char *instuction_line);

/*
** Eddie's fns
*/
int					is_valid_mnemonic(char *str);
int					is_label(char *str);
int					is_valid_label(char *str);
int					error_check_line(char *line);
int					is_name(char *line);
int					is_comment(char *line);
int					is_valid_name(char *line);
int					is_valid_comment(char *line);
/*
** Fred's fns
*/

typedef struct		s_input
{
	char			*line;
	int				line_no;
	int				byte_count;
	t_byte			byte_code;
	t_byte			param_encoding;
	t_bool			is_label;
	t_opnum			instruction_type;
	struct s_input	*next;
}					t_input;

void				input_del(t_input **ahead);
void				gen_bytecode(t_input *elem);
t_input				*file_tolist(char *fname);
t_bool				parse_listinfo(t_input *ahead);
t_bool				is_validfile(t_input *ahead);
void				print_cor(t_input *head, char *fname);
void				inlstadd(t_input **ahead, t_input *elem);
t_input				*inlstnew(char	*line, int line_no, t_bool is_label);

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
