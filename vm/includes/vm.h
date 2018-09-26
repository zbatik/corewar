/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 12:48:49 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 16:00:21 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../../shared/includes/shared.h"
# include "structs.h"
# define PARA_ENCODE_BYTE (core->mem[(cursor->pc + 1) % MEM_SIZE])
# define CORE_VAL(x)(core->mem[(cursor->pc + x) % MEM_SIZE])
# define PC(x) ((cursor->pc + x) % MEM_SIZE)
# define PBP (core->pbp)

int			init_core(t_core *core);

int			parse_input(t_core *core, int c, char **v);

int			creat_players(t_core *core);
t_player	*get_player_from_num(t_core *core, int player_num);

int			load(t_core *core);

int			duplicate_process(t_core *core, t_process *cursor, int jump);
void		process_add(t_process *cursor, int pc, int player_num, int ind);

int			byte_counter(t_core *core, int pc, t_opnum op);
int			bytes_or_gen(t_byte eb);
int			bytes_st(t_byte eb);
int			bytes_ld_gen(t_byte eb);
int			bytes_sti(t_byte eb);
int			bytes_ldi_gen(t_byte eb);

int			game_loop(t_core *core);
int			update_cycles_to_execute(t_byte current, t_process *cursor);

void		print_instr_info(t_core *core, t_process *cursor, t_opnum op);
void		print_cursor_info(t_core *core, t_process *cursor);
void		print_cylce_info(t_core *core);
void		print_players(t_core *core);
void		print_mem(t_core *core);

void		interactive(t_core *core);

int			num_players_alive(t_core *core);
int			num_cursors_alive(t_core *core);
void		check_players_alive(t_core *core);
void		check_cursors_alive(t_core *core);

void		end_cycle_checks_checks(t_core *core);

void		exit_on_error(char *error_msg);

int			cpy_mem_to_reg(t_core *core, t_process *cursor, int reg,
			int start_ind);
int			cpy_reg_to_reg(t_process *cursor, int dst, int src);
int			cpy_reg_to_mem(t_core *core, t_process *cursor, int reg,
			int start_ind);
int			cpy_straight_to_mem(t_core *core, t_process *cursor, t_byte *info,
			int start_ind);
int			cpy_int_to_reg(t_process *cursor, int n, int reg);

int			convert_bytes_to_int(t_core *core, int start, int len);
int			convert_reg_to_int(t_process *cursor, int reg, int *output);

int			corrupted_encoding_byte(t_core *core);
t_byte		*ft_bytencpy(unsigned char *dst, const unsigned char *src, int len);
t_bool		valid_reg(int reg);

int			ft_add(t_core *core, t_process *cursor);
int			ft_sub(t_core *core, t_process *cursor);
int			ft_aff(t_core *core, t_process *cursor);
int			ft_fork(t_core *core, t_process *cursor);
int			ft_lfork(t_core *core, t_process *cursor);
int			general_processing(t_core *core, t_process *cursor, t_opnum op);
void		modify_carry(t_core *core, t_process *cursor, int val);
int			get_dir(t_core *core, t_process *cursor, int start, t_opnum op);
int			get_indir(t_core *core, t_process *cursor, int start, t_opnum op);
int			ft_live(t_core *core, t_process *cursor);
int			ft_ld(t_core *core, t_process *cursor);
int			ft_lld(t_core *core, t_process *cursor);
int			ft_ldi(t_core *core, t_process *cursor);
int			ft_lldi(t_core *core, t_process *cursor);
int			ft_or_gen(t_core *core, t_process *cursor, t_opnum op);
int			ft_and(t_core *core, t_process *cursor);
int			ft_or(t_core *core, t_process *cursor);
int			ft_xor(t_core *core, t_process *cursor);
int			ft_st(t_core *core, t_process *cursor);
int			ft_sti(t_core *core, t_process *cursor);
int			sti_rrr(t_core *core, t_process *cursor, int *ind1, int *ind2);
int			sti_rdr(t_core *core, t_process *cursor, int *ind1, int *ind2);
int			sti_rir(t_core *core, t_process *cursor, int *ind1, int *ind2);
int			ft_zjmp(t_core *core, t_process *cursor);
int			ldi_idr(t_core *core, t_process *cursor, int *param1, int *param2);
int			ldi_drr(t_core *core, t_process *cursor, int *param1, int *param2);
int			ldi_ddr(t_core *core, t_process *cursor, int *param1, int *param2);
int			ldi_rdr(t_core *core, t_process *cursor, int *param1, int *param2);
int			ldi_irr(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_rrr(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_rir(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_rdr(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_dir(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_ddr(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_drr(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_idr(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_iir(t_core *core, t_process *cursor, int *param1, int *param2);
int			op_irr(t_core *core, t_process *cursor, int *param1, int *param2);

#endif
