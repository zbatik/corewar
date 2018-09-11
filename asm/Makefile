# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 14:31:36 by mdilapi           #+#    #+#              #
#    Updated: 2018/09/11 14:49:51 by emaune           ###   ########.fr        #
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
SRC_FILES		=	args_are_valid.c \
					check_params.c \
					check_and_or.c \
					check_fork_and_lld.c \
					check_ldi_and_sti.c \
					check_live_and_ld.c \
					check_lldi_and_lfork.c \
					check_st_and_add.c \
					check_sub_and_aff.c \
					check_xor_and_zjmp.c \
					error_check_data.c \
					error_check_line.c \
					file_tolist.c \
					inlstadd.c \
					inlstnew.c \
					input_del.c \
					inst_to_enum.c \
					is_dir_indr_reg.c \
					is_ignorable_line.c \
					is_label.c \
					is_valid_mnemonic.c \
					is_valid_name_comment.c \
					label.c \
					main.c \
					remove_comment.c \
					remove_spaces.c \
					parse_listinfo.c \
					store_input.c \
					

all: clean $(NAME)
$(NAME):
	make -s -C $(LIB_DIR)
	$(CC) $(FLAGS) $(SRC_PATH) $(SHARED_PATHS) $(LIB) $(INCLUDES)  -o $(NAME)

clean:
	rm -f $(NAME)

	
