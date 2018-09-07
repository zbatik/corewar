/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:10:25 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/07 18:43:50 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

// check number hasn't been assigned already

static int  next_avi_num(t_core *core)
{
    int num;
    int i;
    int match;

    num = -1;
    while (++num < core->num_players)
    {
        i = -1;
        match = 0;
        while (++i < core->num_players)
        {
            if (num == core->players[i].num)
            {
                match = 1;
                break ;
            }
        }
        if (!match)
            return (num);
    }
    return (-1);
}

static int  ft_isposint(char *num)
{
    int n;

    if (!ft_isnumber(num))
        exit_on_error("Error: non-number arg value");
    n = ft_atoi(num);
    if (!ft_isint(num))
        exit_on_error("Error: non-int arg value");
    if (n < 0)
        exit_on_error("Error: negative arg value");
    return (n);
}

static int parse_dump(t_core *core, int c, char **v)
{
    if (c > 2)
    {
        printf("v0: %s is -dump %d\n", v[0],ft_strequ(v[0], "-dump"));
        printf("v1: %s\n", v[1]);
        if (ft_strequ(v[0], "-dump"))
        {
            core->dump = 1;
            core->cycles_to_dump = ft_isposint(v[1]);
        }
    }
    return (1);
}

static int parse_players(t_core *core, int c, char **v)
{
    int i;

    i = -1;
    while (++i < c)
    {
        core->num_players += 1;
        if (core->num_players > MAX_PLAYERS)
            exit_on_error("Error: too many players");
        ft_putendl(v[i]);
        if (ft_strequ(v[i], "-n"))
        {
            ft_putendl("FLAG -n");
            i++;
            if (i >= c)
                exit_on_error("Error: invalid argument");
            core->players[core->num_players - 1].num = ft_isposint(v[i++]);
            if (i >= c)
                exit_on_error("Error: invalid argument");

        }
        else
            core->players[core->num_players - 1].num = next_avi_num(core);
        core->players[core->num_players - 1].file_name = v[i];
    }
    return (1);
}

int parse_input(t_core *core, int c, char **v)
{
    parse_dump(core, c, v);
    if (1 == core->dump)
    {
        ft_putendl("DUMP");
        v = v + 2;
        c = c - 2;
    }
    parse_players(core, c, v);
    return (1);
}