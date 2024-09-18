NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = main.c pipex.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re