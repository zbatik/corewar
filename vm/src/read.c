/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:38:34 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/07 12:54:55 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include <stdio.h>

static unsigned int rev_endian(unsigned int num)
{
    unsigned int swapped;

    swapped = ((num>>24)&0xff) | // move byte 3 to byte 0
                    ((num<<8)&0xff0000) | // move byte 1 to byte 2
                    ((num>>8)&0xff00) | // move byte 2 to byte 1
                    ((num<<24)&0xff000000);
    return (swapped);
}

int read_file(char *file_name, t_player *player)
{
    char         header_info[sizeof(header_t)]; 
    header_t    *header;
    int         ret;
    int         fd;

    //check file_name is a .cor
    fd = open(file_name, O_RDONLY);
    ret = read(fd, header_info, sizeof(header_t));
    header = (header_t *)header_info;
    if (rev_endian(header->magic) != COREWAR_EXEC_MAGIC)
         exit_on_error("Error: not a valid file .cor binary");
    if (ret != sizeof(header_t))
        exit_on_error("Error: invalid read");
    ft_strcpy((char*)player->name, header->prog_name);
    ft_strcpy((char*)player->comment, header->comment);
    player->size = rev_endian(header->prog_size);
    read(fd, player->program, player->size);
    return (1);
}