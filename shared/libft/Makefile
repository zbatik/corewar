# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/24 11:33:49 by zbatik            #+#    #+#              #
#    Updated: 2018/08/03 19:12:27 by zack             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIB     = libft.a
FLAGS	= -Wall -Wextra -Werror
DIRS    = char/ conv/ lst/ math/ put/ file/ mem/ str/
CFILES	= $(addsuffix *.c,$(DIRS))
OBJDIR	= obj/

all : $(OBJDIR)
	gcc $(FLAGS) $(CFILES) -c
	mv *.o $(OBJDIR)
	ar rc $(LIB) $(join $(OBJDIR),*.o)
	ranlib $(LIB)

$(OBJDIR) :
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re
