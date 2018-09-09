# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 14:31:36 by mdilapi           #+#    #+#              #
#    Updated: 2018/09/06 15:22:28 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= asm_us
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
SRC_FILES		=	error_check_line.c\
					file_tolist.c \
					inlstadd.c \
					inlstnew.c \
					input_del.c \
					inst_to_enum.c \
					is_label.c \
					is_valid_mnemonic.c \
					is_valid_name_comment.c \
					label.c \
					main.c \
					parse_listinfo.c \
					store_input.c \
					

all: clean $(NAME)
$(NAME):
	make -s -C $(LIB_DIR)
	$(CC) $(FLAGS) $(SRC_PATH) $(SHARED_PATHS) $(LIB) $(INCLUDES)  -o $(NAME)

clean:
	rm -f $(NAME)

	
