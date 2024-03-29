NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)

%.o: %.c push_swap.h
		$(CC) $(CFLAGS)  -o $@ -c $<

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean