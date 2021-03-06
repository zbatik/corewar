# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zbatik <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 14:31:36 by mdilapi           #+#    #+#              #
#    Updated: 2018/09/26 12:42:46 by emaune           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= asm
CC				= gcc
FLAGS			= -Wall -Werror 
LIB_DIR			= ../shared/libft/
LIB				= $(join $(LIB_DIR),libft.a)

INCLUDES		=-I./includes/

SHARED_DIR		= ../shared/src/
SHARED_PATHS	= $(addprefix $(SHARED_DIR),$(SHARED_FILES))
SHARED_FILES 	= 	op_info.c \
					revendian.c \
					is_valid_filename.c \

SRC_DIR			= ./src/
SRC_PATH		= $(addprefix $(SRC_DIR),$(SRC_FILES))
SRC_FILES		=	args_are_valid.c \
					arr_len.c \
					check_duplicates.c \
					check_commas.c \
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
					exit_function.c \
					file_tolist.c \
					free_input.c \
					gen_bytecode.c \
					get_label.c \
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
					convert_spaces.c \
					parse_listinfo.c \
					print.c \
					print_cor.c \
					print_error_and_no_par.c \
					print_error_and_2.c \
					print_or_error_1.c \
					print_or_error_2.c \
					print_fork_error_1.c \
					print_fork_error_2.c \
					print_lld_error_1.c \
					print_lld_error_2.c \
					print_lldi_error_1.c \
					print_lldi_error_2.c \
					print_lfork_error_1.c \
					print_lfork_error_2.c \
					print_aff_error_1.c \
					print_aff_error_2.c \
					print_sub_error_1.c \
					print_sub_error_2.c \
					print_ldi_error_1.c \
					print_ldi_error_2.c \
					print_sti_error_1.c \
					print_sti_error_2.c \
					print_xor_error_1.c \
					print_xor_error_2.c \
					print_zjmp_error_1.c \
					print_zjmp_error_2.c \
					print_live_error_1.c \
					print_live_error_2.c \
					print_ld_error_1.c \
					print_ld_error_2.c \
					print_st_error_1.c \
					print_st_error_2.c \
					print_add_error_1.c \
					print_add_error_2.c \
					store_input.c \

all: clean $(NAME)

$(NAME):
	make -s -C $(LIB_DIR)
	gcc  -o $(NAME) $(FLAGS) $(SRC_PATH)  $(SHARED_PATHS) $(LIB)

clean:
	rm -f $(NAME)

fclean: clean
	rm -f $(LIB)

re: fclean all

.PHONY: clean all fclean re