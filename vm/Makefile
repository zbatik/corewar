# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/09/06 13:45:07 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM			= core
LIB			= libft/libft.a
FLAGS		= -Wall -Werror -Wextra
FILES		= src/main.c src/disp.c src/read.c

all: clean $(VM)
$(LIB):
	make -s -C ../shared/libft
$(VM) : $(LIB)
	gcc $(FLAGS) $(FILES) ../shared/libft/libft.a -o $(VM)
clean :
	rm -f $(VM)
fclean : clean
	rm -f $(LIB)
norm :
	norminette $(FILES) *.h
re : fclean all