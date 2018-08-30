# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/08/30 14:52:00 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM			= core
LIB			= libft/libft.a
FLAGS		= -Wall -Werror -Wextra
FILES		= main.c disp.c

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
