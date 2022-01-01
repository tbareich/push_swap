NAME = push_swap
PUSH_SWAP_HEADER = push_swap.h
OBJS = push_swap.o checker.o src/check_args.o src/error.o \
		src/checker/reader.o
PRINTF = ft_printf
PRINTF_LIB =  ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra


all: sub-make $(NAME)

sub-make:
	@$(MAKE) -C $(PRINTF)

$(NAME): $(OBJS) $(PUSH_SWAP_HEADER)
	@$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) -o $(NAME) -I.

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@  $< -I.

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBFT)
	@$(MAKE) -C $(PRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(PRINTF_LIB)

re: fclean  all

.PHONY: all clean fclean re