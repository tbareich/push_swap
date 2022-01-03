# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/02 00:58:39 by tbareich          #+#    #+#              #
#    Updated: 2022/01/02 00:58:39 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER_NAME = checker
PUSH_SWAP_HEADER = push_swap.h
OBJS = src/check_args.o
		
PUSH_SWAP_OBJS = push_swap.o 
CHECKER_OBJS =  checker.o  src/checker/reader.o src/checker/check_opt.o
PRINTF = ft_printf
PRINTF_LIB =  ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra


all: sub-make $(NAME)

sub-make:
	@$(MAKE) -C $(PRINTF)

$(NAME): $(OBJS) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS) $(PUSH_SWAP_HEADER)
	@$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP_OBJS)$(PRINTF_LIB) -o $(NAME) -I. -Ift_printf
	@$(CC) $(CFLAGS) $(OBJS) $(CHECKER_OBJS) $(PRINTF_LIB)  -o $(CHECKER_NAME) -I. -Ift_printf

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@  $< -I. -Ift_printf

clean:
	@rm -rf $(OBJS)
	@rm -rf $(PUSH_SWAP_OBJS)
	@rm -rf $(CHECKER_OBJS)
	@rm -rf $(LIBFT)
	@$(MAKE) -C $(PRINTF) clean

fclean: clean
	@rm -f $(NAME)
	@rm -f $(CHECKER_NAME)
	@rm -f $(PRINTF_LIB)

re: fclean  all

.PHONY: all clean fclean re