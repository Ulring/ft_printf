NAME = ft_printf

FILES = ft_atoi.c ft_itoi.c ft_putchar.c ft_putstr.c ft_strcpy.c\
		ft_strlen.c ft_convert_base.c ft_param_to_tab.c ft_putnbr.c\
		ft_split.c ft_strjoin.c ft_unsigned_putnbr.c
SRCS = $(addprefix srcs/, $(FILES))

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${NAME}.c ${OBJS}
	${CC} ${CFLAGS} $@.c ${OBJS} -o $@

srcs/%.o: srcs/%.c
	${CC} ${CFLAGS} -c ${@:.o=.c} -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
