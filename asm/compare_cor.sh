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
COR_FILE=$(basename "$1" .s).cor
$ASM_US $1
hexdump $COR_FILE > dump_us
$ASM_BASE $1
hexdump $COR_FILE > dump_base
diff dump_base dump_us > dif
cat dif
rm dif dump_base dump_us