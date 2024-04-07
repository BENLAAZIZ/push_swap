NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address

RM = rm -f

SRC = ft_split.c ft_atoi.c push_swap.c free_function.c list_function.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 

%.o: %.c push_swap.h
		$(CC) $(CFLAGS)  -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean