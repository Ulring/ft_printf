# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansoulim <ansoulim@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 06:27:46 by ansoulim          #+#    #+#              #
#    Updated: 2022/12/02 03:47:58 by ansoulim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

SRC_DIR     = src

OBJ_DIR     = obj

INC_DIR     = include

BIN_DIR 	= bin

TEST_DIR	= test

DEBUG_CFLAGS=

RM 			= rm -rf

CC 			= gcc

#CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)
CFLAGS		= -I$(INC_DIR)

HEADERS     = $(addprefix $(INC_DIR)/,$(INC_FILES))
SRCS        = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
TESTS 		= $(addprefix $(TEST_DIR)/,$(TEST_FILES))
TARGET 		= $(addprefix $(BIN_DIR)/,$(NAME))

OBJ_NAME	= $(SRC_FILES:.c=.o)

INC_FILES	= ft_printf.h

SRC_FILES   =	ft_strlen.c				\
				ft_putchar.c			\
				ft_putstr.c				\
				ft_putnbr.c				\
				ft_print_char.c			\
				ft_print_string.c		\
				ft_print_pointer.c		\
				ft_print_decimal.c		\
				ft_print_integer.c		\
				ft_print_unsigned.c		\
				ft_print_lower_hex.c	\
				ft_print_upper_hex.c	\
				ft_print_modulo.c		\
				ft_count_digits.c		\
				ft_hex_length.c			\
				ft_calculate_pointer.c	\
				ft_calculate_lower_hex.c\
				ft_calculate_upper_hex.c\
				ft_printf.c

TEST_FILES	=	main.c

DIRS: 
	if test ! -d $(OBJ_DIR); then mkdir $(OBJ_DIR); fi
	if test ! -d $(BIN_DIR); then mkdir $(BIN_DIR); fi

all	: DIRS ${NAME}

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c $(HEADER)	
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) -c $< -o $@

$(NAME)			: $(OBJS)
	ar rcs $(TARGET) $(OBJS)

clean           :
				$(RM) $(OBJS)

fclean          : clean
				$(RM) $(TARGET)

re              : fclean all

.PHONY          : all, clean, fclean, re

test			: all
				gcc $(TEST_FILES) bin/libftprintf.a -o test -L.
				./test
