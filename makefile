
NAME = push_swap
OBJS = push_swap.o
PRINTF = ft_printf
PRINTF_LIB =  ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	cd $(PRINTF) && $(MAKE)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT)
	cd $(PRINTF) &&  $(MAKE) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(PRINTF)/libftprintf.a

re: fclean all
