# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansoulim <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 04:03:05 by ansoulim          #+#    #+#              #
#    Updated: 2022/12/02 04:03:11 by ansoulim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	= libftprintf.a

CC          	= gcc

CFLAGS      	= -Wall -Wextra -Werror -I$(INC_DIR)

RM          	= rm -rf

SRC_DIR     	= src

OBJ_DIR     	= obj

INC_DIR     	= include

HEADERS			= $(addprefix $(INC_DIR)/,$(INC_FILES))

SRCS        	= $(addprefix $(SRC_DIR)/,$(SRC_FILES))

OBJS        	= $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

SRC_FILES   	=	ft_strlen.c				\
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

INC_FILES		= ft_printf.h

OBJ_NAME        = $(SRC_FILES:.c=.o)

$(OBJ_DIR)/%.o  : $(SRC_DIR)/%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME)         : ${OBJS}
				ar rcs ${NAME} ${OBJS}

all             : ${NAME}

clean           :
				${RM} ${OBJS}

fclean          : clean
				${RM} ${NAME}

re              : fclean all

.PHONY          : all, clean, fclean, re
