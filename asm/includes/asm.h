/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 13:29:35 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/26 16:54:22 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../shared/includes/shared.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

# define DEBUG 1
# define IND_DBL 4;
# define ASM_REG 1
# define ASM_DIR 2
# define NUM_SMALL_DIR 6

int					is_valid_mnemonic(char *str);
int					is_label(char *str);
int					is_valid_label(char *str);
int					is_name(char *line);
int					is_comment(char *line);
int					is_valid_name(char *line);
int					is_valid_comment(char *line);
int					is_ignorable_line(char *line);
void				remove_comment(char *line);
void				convert_spaces(char *line);
int					check_commas(char *line);
int					arr_len(char **arr);

typedef struct		s_input
{
	char			*line;
	char			args[MAX_ARGS_NUMBER];
	int				line_no;
	int				byte_count;
	t_byte			*byte_code[MAX_ARGS_NUMBER + 1];
	t_byte			param_encoding;
	t_bool			is_label;
	t_opnum			instruction_type;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

typedef struct		s_main
{
	t_input			*input;
	t_input			*temp_input;
	unsigned int	total_player_size;
	char			**ins;
}					t_main;

void				input_del(t_input **ahead);
void				gen_bytecode(t_input *ahead, t_input *elem,
					int curr_byte_count);
t_input				*file_tolist(char *fname);
t_bool				parse_listinfo(t_main *var);
t_bool				is_validfile(t_input *ahead);
void				print_cor(t_main *var, char *fname);
void				inlstadd(t_input **ahead, t_input *elem);
t_input				*inlstnew(char	*line, int line_no, t_bool is_label);
int					is_wsstring(const char *str);
int					string_to_encoding(char str[4]);

t_opnum				inst_to_enum(char *str);
t_opinfo			index_opinfo(t_opnum op_index);
int					instruction_byte_size(t_input *input);
t_input				*get_label(t_input *head, const char *str);
void				swapnfree(char **var, char *new_val);
void				print_hex(unsigned int num);
int					is_smalldir(int opnum, int arg_num);
int					exit_function(t_main *var);
int					get_size(char arg);
void				free_split(char **s);
int					arg_byte_count(char *str);
void				putstr_ignore(const char *str, char c);

void				store_input(t_main *var, char *fname);
void				error_check_data(t_main *var);
void				error_check_line(t_main *var, char *line, int ln);
int					args_are_valid(char *args);
int					is_direct(char *arg, t_main *var);
int					is_indirect(char *arg, t_main *var);
int					is_register(char *arg, t_main *var);
int					check_live(char **args, t_main *var);
int					check_ld(char **args, t_main *var);
int					check_st(char **args, t_main *var);
int					check_add(char **args, t_main *var);
int					check_sub(char **args, t_main *var);
int					check_and(char **args, t_main *var);
int					check_or(char **args, t_main *var);
int					check_xor(char **args, t_main *var);
int					check_zjmp(char **args, t_main *var);
int					check_ldi(char **args, t_main *var);
int					check_sti(char **args, t_main *var);
int					check_fork(char **args, t_main *var);
int					check_lld(char **args, t_main *var);
int					check_lldi(char **args, t_main *var);
int					check_lfork(char **args, t_main *var);
int					check_aff(char **args, t_main *var);
void				check_params(char **args, t_main *var);
void				free_input(t_input *input);
void				check_duplicate_label(t_main *var);
void				check_multiple_name(t_main *var);
void				check_multiple_comment(t_main *var);
void				print_error_and_no_par(t_main *var, char **args);
void				print_error_and_2(t_main *var, char **par);
void				print_or_error_1(t_main *var, char **args);
void				print_or_error_2(t_main *var, char **args);
void				print_fork_error_1(t_main *var, char **args);
void				print_fork_error_2(t_main *var, char **par);
void				print_lld_error_1(t_main *var, char **args);
void				print_lld_error_2(t_main *var, char **args);
void				print_lldi_error_1(t_main *var, char **args);
void				print_lldi_error_2(t_main *var, char **par);
void				print_lfork_error_1(t_main *var, char **args);
void				print_lfork_error_2(t_main *var, char **par);
void				print_aff_error_1(t_main *var, char **args);
void				print_aff_error_2(t_main *var, char **par);
void				print_sub_error_1(t_main *var, char **args);
void				print_sub_error_2(t_main *var, char **par);
void				print_ldi_error_1(t_main *var, char **args);
void				print_ldi_error_2(t_main *var, char **par);
void				print_sti_error_1(t_main *var, char **args);
void				print_sti_error_2(t_main *var, char **par);
void				print_xor_error_1(t_main *var, char **args);
void				print_xor_error_2(t_main *var, char **par);
void				print_zjmp_error_1(t_main *var, char **args);
void				print_zjmp_error_2(t_main *var, char **par);
void				print_live_error_1(t_main *var, char **args);
void				print_live_error_2(t_main *var, char **par);
void				print_ld_error_1(t_main *var, char **args);
void				print_ld_error_2(t_main *var, char **par);
void				print_st_error_1(t_main *var, char **args);
void				print_st_error_2(t_main *var, char **par);
void				print_add_error_1(t_main *var, char **args);
void				print_add_error_2(t_main *var, char **par);
#endif
