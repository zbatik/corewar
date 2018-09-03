# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/09/03 17:44:20 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM			= core
LIB			= libft/libft.a
FLAGS		= -g -Wall -Werror -Wextra
FILES		= main.c disp.c instr.c read.c player.c

all: clean $(VM)
$(LIB):
	make -s -C ./libft
$(VM) : $(LIB)
	gcc $(FLAGS) $(FILES) $(LIB) -o $(VM)
clean :
	rm -f $(VM)
fclean : clean
	rm -f $(LIB)
norm :
	norminette $(FILES) *.h
re : fclean all
