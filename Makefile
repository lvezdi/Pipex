NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = pruebas.c

LIB = Libft/libft.a

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C Libft
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean :
	@$(MAKE) clean -C Libft
	$(RM) $(OBJS)

fclean : clean
	@$(MAKE) fclean -C Libft
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re