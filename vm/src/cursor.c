/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 12:31:30 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/09 13:52:32 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

t_process *process_new(int pc, int player_num)
{
    t_process   *cursor;
    int         i;
    
	printf("size of curser : %zu\nsizeof process : %zu\n",
		sizeof(cursor), sizeof(t_process));
	cursor = (t_process *)malloc(100);
    cursor->pc = pc;
    cursor->carry = 0;
//    cursor->reg = malloc(sizeof(int) * REG_SIZE);
    cursor->reg[0] = player_num;
    i = 1;
    while (i < REG_NUMBER)
        cursor->reg[i++] = 0;
    cursor->next = NULL;
    return (cursor);
}

void    process_add(t_process **head, t_process *new)
{
    t_process *proc;

    if (*head == NULL)
    {
        *head = new;
        return ;
    }
    proc = *head;
    while (proc->next != NULL)
        proc = proc->next;
    proc->next = new;
}

//void    process_dup(t_process **head, t_process *dup);

void    process_del(t_process **head)
{
    t_process *tmp;

    while (*head)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    }
}
