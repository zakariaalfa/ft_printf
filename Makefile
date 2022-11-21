NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_printf_utils.c
AR = ar -rc
OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $@ $^

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ)
fclean : clean
	rm -rf libftprintf.a
re : fclean all