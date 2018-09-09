# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 12:48:33 by zbatik            #+#    #+#              #
#    Updated: 2018/09/09 13:33:25 by zbatik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= core
CC				= gcc
FLAGS			= -g -Wall -Werror -Wextra
LIB_DIR			= ../shared/libft/
LIB				= $(join $(LIB_DIR),libft.a)

INCLUDES		=-I./includes/

SHARED_DIR		= ../shared/src/
SHARED_PATHS	= $(addprefix $(SHARED_DIR),$(SHARED_FILES))
SHARED_FILES 	= op_info.c

SRC_DIR			= ./src/
SRC_PATH		= $(addprefix $(SRC_DIR),$(SRC_FILES))
SRC_FILES		=	main.c \
				disp.c \
				players.c \
				exit.c \
				init.c \
				input.c \
				load.c \
				cursor.c \
				game.c 

INST_DIR		= ./src/instructions/
INST_PATHS		= $(addprefix $(INST_DIR),$(INST_FILES))
INST_FILES		= ft_live.c \
				ft_ld.c \
				ft_st.c \
				ft_add.c \
				ft_sub.c \
				ft_abd.c \
				ft_or.c \
				ft_xor.c \
				ft_zjmp.c \
				ft_ldi.c \
				ft_sti.c \
				ft_fork.c \
				ft_lld.c \
				ft_lldi.c \
				ft_lfork.c \
				ft_aff.c

ALL_FILES		= $(SRC_PATH) $(SHARED_PATHS) $(INST_PATHS)

all: clean $(NAME)
$(NAME): $(LIB)
	$(CC) $(FLAGS)  $(LIB) $(INCLUDES) $(ALL_FILES) -o $(NAME)
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
