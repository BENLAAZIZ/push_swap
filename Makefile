NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRC = ft_split.c ft_atoi.c push_swap.c free_function.c list_function.c check_paring.c stack_operation1.c stack_operation2.c

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