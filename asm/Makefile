# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 14:31:36 by mdilapi           #+#    #+#              #
#    Updated: 2018/09/04 14:31:37 by mdilapi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=asm_us
CC=gcc
FLAGS=-Wall -Werror -Wextra
INCLUDES=./includes/
LDFLAGS=-L../libft
LFT=-lft 
SRC=./src/
SRC_NAME= main.c \

OBJ=$(SRC_NAME:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(LDFLAGS) $(LFT) $(OBJ) -o $(NAME)

$(OBJ): $(addprefix $(SRC),$(SRC_NAME))
	