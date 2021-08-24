NAME = philosophers

SRC = utils.c			\
		philosophers.c	\

FLAGS = -Werror -Wextra -Wall -fsanitize=address

$(NAME):
	gcc $(SRC) $(FLAGS) -pthread -o $(NAME)

all : $(NAME)

clean:
	/bin/rm -f

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
