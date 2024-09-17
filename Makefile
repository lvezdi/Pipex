NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \

OBJS = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

clean : 
		$(RM) $(OBJS)

fclean : clean
			$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re