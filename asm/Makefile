# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 14:31:36 by mdilapi           #+#    #+#              #
#    Updated: 2018/09/05 17:57:17 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= asm_us
CC				= gcc
FLAGS			= -Wall -Werror -Wextra
LIB_DIR			= ../shared/libft/
LIB				= $(join $(LIB_DIR),libft.a)

SHARED_DIR		= ../shared/src/
SHARED_PATHS	= $(addprefix $(SHARED_DIR),$(SHARED_FILES))
SHARED_FILES 	= op_info.c \

SRC_DIR			= ./src/
SRC_PATH		= $(addprefix $(SRC_DIR),$(SRC_FILES))
SRC_FILES		= main_test.c \
					inst_to_enum.c \
					label.c

all: clean $(NAME)
$(NAME):
	make -s -C $(LIB_DIR)
	$(CC) $(FLAGS) $(SRC_PATH) $(SHARED_PATHS) $(LIB) -o $(NAME)

clean:
	rm -f $(NAME)

	