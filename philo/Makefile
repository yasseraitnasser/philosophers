NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
FILES = main.c parsing.c ft_atoi.c algo.c \
	ft_lstnew.c ft_lstadd_back.c ft_lstsize.c ft_lstlast.c \

FILES_o = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(FILES_o)
	$(CC) $(CFLAGS) $(FILES_o) -o $(NAME)

clean:
	rm -f $(FILES_o)

fclean: clean
	rm -f $(NAME)

re: fclean all
