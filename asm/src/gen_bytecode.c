/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_bytecode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 13:46:59 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/18 15:37:49 by emaune           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	g_smalldir[] = {9, 10, 11, 12, 14, 15};

int		is_smalldir(int opnum, int arg_num)
{
	int i;

	i = 0;
	while (i < NUM_SMALL_DIR)
		if (g_smalldir[i++] == opnum)
			return (TRUE);
	return (FALSE);
}

void	free_split(char **s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		free(s[i++]);
	free(s[i]);
	free(s);
}

void	set_opcode(t_input *elem)
{
	int		inter;
	t_opnum op;

	op = inst_to_enum((char*)elem->line);
	elem->byte_code[0] = (t_byte *)malloc(sizeof(t_byte));
	inter = (index_opinfo(op)).op_number;
	ft_memmove(elem->byte_code[0], &inter, sizeof(t_byte));
}

int		inter_calc(char arg, char *tmp, int curr_byte_count, t_input *ahead)
{
	int	inter;
	int	tmp_size;

	inter = 0;
	tmp_size = get_size(arg);
	if (arg == 'D' || arg == 'd')
	{
		inter = (int)rev_endian((unsigned int)(tmp[1] == ':') ?
		get_label(ahead, tmp + 2)->byte_count
		- curr_byte_count : ft_atoi(tmp + 1));
		inter = (tmp_size == ASM_DIR) ? inter << 16 | inter >> 16 : inter;
	}
	else if (arg == 'I')
	{
		inter = (int)rev_endian((unsigned int)(tmp[0] == ':') ?
		get_label(ahead, tmp + 1)->byte_count - curr_byte_count : ft_atoi(tmp));
		inter = inter << 16 | inter >> 16;
	}
	else
		inter = ft_atoi(tmp + 1);
	return (inter);
}

void	gen_bytecode(t_input *ahead, t_input *elem, int curr_byte_count)
{
	int		i;
	char	*tmp;
	char	**split;
	int		inter;
	int		tmp_size;

	set_opcode(elem);
	tmp = ft_strchr((char *)elem->line, '\t') + 1;
	split = ft_strsplit(tmp, ',');
	i = 0;
	while (elem->args[i] != '\0')
	{
		tmp = split[i];
		while (ft_isws(*tmp) == TRUE)
			tmp++;
		tmp_size = get_size(elem->args[i]);
		elem->byte_code[i + 1] = (t_byte *)malloc(sizeof(t_byte) * tmp_size);
		inter = inter_calc(elem->args[i], tmp, curr_byte_count, ahead);
		ft_memmove(elem->byte_code[i + 1], &inter, sizeof(t_byte) * tmp_size);
		i++;
	}
	free_split(split);
}
