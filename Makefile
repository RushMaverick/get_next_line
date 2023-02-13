
NAME = get_next_line.a

INC = get_next_line.h

SRC = \
get_next_line.c get_next_line_utils.c

all:  $(NAME)

$(NAME): 
	cc -Wall -Wextra -Werror -c $(SRC) -I $(INC)
	ar rc $(NAME) $(SRC:.c=.o) $(NAME)
	cc -Wall -Wextra -Werror -c $(SRC) -I $(INC)
	ar rc $(NAME) $(SRC:.c=.o)

clean:
	rm -f $(SRC:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all