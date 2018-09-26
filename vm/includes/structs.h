/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 15:26:50 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 15:56:41 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../../shared/includes/shared.h"

typedef	struct		s_player
{
	char			*file_name;
	int				num;
	t_bool			dead;
	t_bool			alive;
	char			name[PROG_NAME_LENGTH + 1];
	char			comment[COMMENT_LENGTH + 1];
	int				size;
	t_byte			program[CHAMP_MAX_SIZE];
	unsigned int	start_pos;
}					t_player;

typedef struct		s_process
{
	int				id;
	int				pc;
	int				cycles_to_execute;
	t_byte			reg[REG_NUMBER][REG_SIZE];
	t_bool			alive;
	t_bool			dead;
	t_bool			carry;
}					t_process;

typedef struct		s_count
{
	int				lives;
	int				cycles;
	int				total_turns;
	int				cycles_to_die;
}					t_count;

typedef struct		s_core
{
	int			(* instructon_fn[16])(struct s_core *core, t_process *cursor);
	t_process	processes[MEM_SIZE];
	int			num_processes;
	t_bool		dump;
	t_bool		interactive;
	t_bool		pbp;
	int			checks;
	t_count		count;
	int			last_alive;
	int			cycles_to_dump;
	int			num_players;
	t_player	players[MAX_PLAYERS];
	t_byte		mem[MEM_SIZE];
	t_byte		colouring[MEM_SIZE];
	int			fd;
}					t_core;

#endif
