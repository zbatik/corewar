/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:38:34 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/26 15:08:19 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int	assign_player_pos(t_core *core)
{
	int i;
	int factor;
	int pos;

	pos = 0;
	factor = MEM_SIZE / core->num_players;
	i = -1;
	while (++i < core->num_players)
	{
		core->players[i].start_pos = pos;
		pos += factor;
	}
	return (1);
}

static int	assign_player_num(t_core *core)
{
	int j;
	int i;
	int num;

	i = -1;
	while (++i < core->num_players)
	{
		if (core->players[i].num == -1)
		{
			j = -1;
			num = 1;
			while (++j < core->num_players)
			{
				if (core->players[j].num == num)
				{
					num++;
					j = -1;
				}
			}
			core->players[i].num = num;
		}
	}
	return (1);
}

static void	validate_player(t_header *header)
{
	int player_size;

	player_size = rev_endian(header->prog_size);
	if (rev_endian(header->magic) != COREWAR_EXEC_MAGIC)
		exit_on_error("Error: not a valid file .cor binary");
	if (player_size > CHAMP_MAX_SIZE || player_size <= 0)
		exit_on_error("Error: invalid player size");
}

static int	read_player_file(t_player *player)
{
	char		header_info[sizeof(t_header)];
	t_header	*header;
	int			ret;
	int			fd;

	if (!is_valid_filename(player->file_name, ".cor"))
		exit_on_error("Error: not a .cor file");
	fd = open(player->file_name, O_RDONLY);
	if (fd < 0)
		exit_on_error("Error: could not read file");
	ret = read(fd, header_info, sizeof(t_header));
	header = (t_header *)header_info;
	validate_player(header);
	if (ret != sizeof(t_header))
		exit_on_error("Error: invalid read");
	ft_strcpy((char*)player->name, header->prog_name);
	ft_strcpy((char*)player->comment, header->comment);
	player->size = rev_endian(header->prog_size);
	read(fd, player->program, player->size);
	return (1);
}

int			creat_players(t_core *core)
{
	int i;

	i = -1;
	while (++i < core->num_players)
	{
		assign_player_num(core);
		assign_player_pos(core);
		read_player_file(&core->players[i]);
	}
	return (1);
}
