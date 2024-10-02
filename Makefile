NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

RM = rm -f

SRC = pipex.c \
		pipex_c.c

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