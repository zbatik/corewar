# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compare_cor.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 14:47:15 by zbatik            #+#    #+#              #
#    Updated: 2018/09/18 15:04:44 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#bin!
ASM_US=./asm_us
ASM_BASE=./asm
COR_FILE=$("$1" .s).cor
$ASM_US $1
hexdump $COR_FILE > dump_us
rm $COR_FILE
echo removed $COR_FILE
$ASM_BASE $1
hexdump $COR_FILE > dump_base
diff dump_base dump_us > dif
echo __________________________
echo $S_FILE
echo __________________________
cat dif
echo
rm dif dump_base dump_us