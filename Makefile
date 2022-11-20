# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansoulim <ansoulim@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 06:27:46 by ansoulim          #+#    #+#              #
#    Updated: 2022/11/16 11:55:31 by ansoulim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a

SRC_DIR     = src

OBJ_DIR     = obj

INC_DIR     = include

BIN_DIR 	= bin

TEST_DIR	= test

#DEBUG_CFLAGS= -O3
DEBUG_CFLAGS=

RM 			= rm -rf

CC 			= gcc

CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR)

HEADERS     = $(addprefix $(INC_DIR)/,$(INC_FILES))
SRCS        = $(addprefix $(SRC_DIR)/,$(SRC_FILES))
OBJS        = $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))
TESTS 		= $(addprefix $(TEST_DIR)/,$(TEST_FILES))
TARGET 		= $(addprefix $(BIN_DIR)/,$(NAME))

OBJ_NAME	= $(SRC_FILES:.c=.o)

INC_FILES	= ft.h ft_flags.h

SRC_FILES   = 	ft_atoi.c			\
				ft_itoa.c			\
				ft_putchar.c		\
				ft_putstr.c			\
				ft_strdup.c			\
				ft_strjoin.c		\
				ft_strlcpy.c		\
				ft_unsigned_putnbr.c\
				ft_convert_base.c	\
				ft_param_to_tab.c	\
				ft_putnbr.c			\
				ft_split.c			\
				ft_strlcat.c		\
				ft_strlen.c			\
				ft_check_char.c		\
				ft_check_integer.c	\
				ft_check_modulo.c	\
				ft_check_string.c	\
				ft_check_upper_hex.c\
				ft_check_decimal.c	\
				ft_check_lower_hex.c\
				ft_check_pointer.c	\
				ft_check_unsigned.c	\
				ft_printf.c

TEST_FILES	=	tests.c

DIRS: 
	if test ! -d $(OBJ_DIR); then mkdir $(OBJ_DIR); fi
	if test ! -d $(BIN_DIR); then mkdir $(BIN_DIR); fi

all	: DIRS ${NAME}

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c $(HEADER)	
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) -c $< -o $@

$(NAME)			: ${OBJS}
	ar rcs $(TARGET) $(OBJS)

clean           :
				$(RM) $(OBJS)

fclean          : clean
				$(RM) $(TARGET)

re              : fclean all

.PHONY          : all, clean, fclean, re

test			: all
				gcc main.c bin/libftprintf.a -o test -Wall -Wextra -Werror -L.
#				./test
