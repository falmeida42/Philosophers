NAME = philosophers

SRC = utils.c			\
		philosophers.c	\

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	gcc $(OBJS) -pthread -o $(NAME)

all : $(NAME)

clean:
	/bin/rm -f $(OBJS) $(OBJSB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
