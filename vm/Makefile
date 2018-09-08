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

NAME			= core
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
LIB_DIR			= ../shared/libft/
LIB				= $(join $(LIB_DIR),libft.a)

INCLUDES		=-I./includes/

SHARED_DIR		= ../shared/src/
SHARED_PATHS	= $(addprefix $(SHARED_DIR),$(SHARED_FILES))
SHARED_FILES 	= op_info.c \

SRC_DIR			= ./src/
SRC_PATH		= $(addprefix $(SRC_DIR),$(SRC_FILES))
SRC_FILES		=	main.c \
				disp.c \
				players.c \
				exit.c \
				init.c \
				input.c \
				load.c \
					

all: clean $(NAME)
$(NAME): $(LIB)
	$(CC) $(FLAGS) $(SRC_PATH) $(SHARED_PATHS) $(LIB) $(INCLUDES)  -o $(NAME)
$(LIB):
	make -s -C $(LIB_DIR)
clean:
	rm -f $(NAME)
fclean: clean
	rm -f $(LIB)
re: fclean all
norm:
	norminette $(SHARED_PATHS) $(SRC_PATH) ../includes/*.h

.PHONY: all clean fclean re norm