NAME = philo

SRC = utils.c			\
		philosophers.c	\
		routine.c		\
		checks.c		\
		forks.c			\
		printer.c		\

FLAGS = -Werror -Wextra -Wall -fsanitize=address

$(NAME):
	gcc $(SRC) $(FLAGS) -pthread -o $(NAME)

all : $(NAME)

clean:
	/bin/rm -f

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
