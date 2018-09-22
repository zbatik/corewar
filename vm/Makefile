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
SHARED_FILES 	= op_info.c \
				revendian.c

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
				game.c \
				helpers.c \
				end_cycle_checks.c \
				interactive.c \
				byte_count.c \
				copy.c

INST_DIR		= ./src/instructions/
INST_PATHS		= $(addprefix $(INST_DIR),$(INST_FILES))
INST_FILES		= ft_live.c \
				ft_ld_gen.c \
				ft_st.c \
				ft_add_gen.c \
				ft_or_gen1.c \
				ft_or_gen2.c \
				ft_zjmp.c \
				ft_ldi_gen.c \
				ft_sti.c \
				ft_fork_gen.c \
				ft_aff.c \
				ft_general.c \
				ft_general_ops1.c \
				ft_general_ops2.c 

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
