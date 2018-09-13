/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revendian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbatik <zbatik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 13:58:39 by zbatik            #+#    #+#             */
/*   Updated: 2018/09/13 14:01:11 by zbatik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int rev_endian(unsigned int num)
{
    unsigned int swapped;

    swapped = ((num>>24)&0xff) | 
                    ((num<<8)&0xff0000) | 
                    ((num>>8)&0xff00) | 
                    ((num<<24)&0xff000000);
    return (swapped);
}