/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 12:38:34 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/07 12:14:25 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"
#include <stdio.h>
/*
static void read_magic(int fd)
{
    t_byte magic[4];
    header_t *header;

    read(fd, magic, 4);
    header = (header_t *)magic;
    if (header->magic != COREWAR_EXEC_MAGIC_REV)
        ft_puterror("Error: not a valid file .cor binary");
        // add exit 
}

static void read_name(int fd, t_player *player)
{
    t_byte  name[PROG_NAME_LENGTH + 1];
    int     ret;    

    ret = read(fd, name, PROG_NAME_LENGTH);
    name[ret] = 0;
    ft_strcpy((char*)player->name, (char*)name);
}

static void read_comment(int fd, t_player *player)
{
    t_byte  comment[COMMENT_LENGTH + 1];
    int     ret; 

    ret = read(fd, comment, COMMENT_LENGTH);
     ft_putendl((char*)comment);
    comment[ret] = 0;
   
    ft_strcpy((char*)player->comment, (char*)comment);
}

int read_file(char *file_name, t_player *player)
{
    int fd;
    //check file name is a .cor file 
    fd = open(file_name, O_RDONLY);
    //player
    read_magic(fd);
    read_name(fd, player);
    read_comment(fd, player);
    return (1);
}
*/
unsigned char    *ft_strrev(char *str)
{
    char    *tmp;
    int     i;
    int     len;

    tmp = ft_strdup(str);
    len = ft_strlen(str);
    i = -1;
    while (++i < len)
    {
        str[i] = tmp[len - 1 - i];
    }
    free(tmp);
    return ((unsigned char *)str);
}

int read_file(char *file_name, t_player *player)
{
    t_byte      header_info[sizeof(header_t)]; 
    header_t    *header;
    int         ret;
    int         fd;

    //check file_name is a .cor
    fd = open(file_name, O_RDONLY);
    ret = read(fd, header_info, sizeof(header_t));
    header = (header_t *)header_info;
    ft_putendl("HER");
    char hat[4] = "hat";
         printf("%s\n", ft_strrev(hat));
     ft_putendl("HER");
    if ((unsigned int)ft_strrev(header->magic) != COREWAR_EXEC_MAGIC)
    {
         ft_puterror("Error: not a valid file .cor binary");
         exit(-1);
    }
    if (ret != sizeof(header_t))
    {
         ft_puterror("Error: missing infomation");
         exit(-1);
    }
    ft_strcpy((char*)player->name, header->prog_name);
    ft_strcpy((char*)player->comment, header->comment);
    player->size = (int)ft_strrev((char*)header->prog_size);
    read(fd, player->program, player->size);
    return (1);
}

