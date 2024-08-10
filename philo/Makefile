NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
FILES = main.c parsing.c ft_atoi.c init.c \
	ft_lstadd_back.c ft_lstnew.c dinner.c time.c \
	routine.c clean.c print_mutex.c utils.c

FILES_o = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) -o $(NAME)

clean:
	rm -f $(FILES_o)

fclean: clean
	rm -f $(NAME)

re: fclean all
