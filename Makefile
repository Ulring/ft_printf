# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ansoulim <ansoulim@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 06:27:46 by ansoulim          #+#    #+#              #
#    Updated: 2022/10/18 18:58:17 by ansoulim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ft_printf.a

SRC_DIR     = src

OBJ_DIR     = obj

INC_DIR     = include

BIN_DIR 	= bin

TEST_DIR	= test

DEBUG_CFLAGS= -g3

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

SRC_FILES   = 	ft_atoi.c		\
				ft_itoa.c		\
				ft_putchar.c	\
				ft_putstr.c		\
				ft_strjoin.c	\
				ft_strlcpy.c	\
				ft_unsigned_putnbr.c\
				ft_convert_base.c\
				ft_param_to_tab.c\
				ft_putnbr.c		\
				ft_split.c		\
				ft_strlcat.c	\
				ft_strlen.c		\
				ft_printf.c

TEST_FILES	=	tests.c

DIRS: 
	if test ! -d $(OBJ_DIR); then mkdir $(OBJ_DIR); fi
	if test ! -d $(BIN_DIR); then mkdir $(BIN_DIR); fi

all	: DIRS ${NAME}

$(TEST_DIR)/bin/%: $(TEST_FILES)
	$(CC) $< $(TESTS) -o $@ -lcriterion
						
test			:	$(TARGET)/$(NAME)

$(OBJ_DIR)/%.o	: $(SRC_DIR)/%.c $(HEADER)	
	$(CC) $(CFLAGS) $(DEBUG_CFLAGS) -c $< -o $@

$(NAME)			: ${OBJS}
	ar rcs ${TARGET} ${OBJS}

clean           :
				${RM} ${OBJS}

fclean          : clean
				${RM} ${TARGET}

re              : fclean all

.PHONY          : all, clean, fclean, re
