# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    _full_test.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 14:47:15 by zbatik            #+#    #+#              #
#    Updated: 2018/09/18 21:07:32 by zack             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_US=../asm_us
ASM_BASE=../asm
S_FILES=$(find . -name "*.s")
for S_FILE in $S_FILES
do
	COR_FILE=$(basename "$S_FILE" .s).cor
	$ASM_US $S_FILE
	sleep 1s
	#COR_FILE=$(basename "$S_FILE" .s).cor
	hexdump $COR_FILE > dump_us
	sleep .5s
	rm $COR_FILE
	echo removed $COR_FILE
	sleep .5s
	$ASM_BASE $S_FILE
	sleep .1s
	hexdump $COR_FILE > dump_base
	diff dump_base dump_us > dif
	echo __________________________
	echo $S_FILE
	echo __________________________
	cat dif
	echo
	rm dif dump_base dump_us
done
