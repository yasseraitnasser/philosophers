NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = main.c parsing.c ft_atoi.c philo.c
FILES_o = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) -o $(NAME)

clean:
	rm -f $(FILES_o)

fclean: clean
	rm -f $(NAME)

re: fclean all
