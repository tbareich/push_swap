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
OBJS = src/check_args.o src/merge_sort.o src/is_sorted.o
		
PUSH_SWAP_OBJS = push_swap.o src/push_swap/chanks_divide.o\
	 			 src/push_swap/search_in_range.o  src/push_swap/move_to_top.o\
				  src/push_swap/find_best_spot.o  src/push_swap/min_max.o 
CHECKER_OBJS = checker.o src/checker/reader.o src/checker/check_opt.o
OPERATIONS_OBJS = src/operations/sx.o src/operations/px.o\
				src/operations/rx.o src/operations/r_a_b.o src/operations/rrx.o\
				src/operations/rr_a_b.o src/operations/s_a_b.o
PRINTF = ft_printf
PRINTF_LIB =  ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra


all: sub-make $(NAME)

sub-make:
	@$(MAKE) -C $(PRINTF)

$(NAME): $(OBJS) $(PUSH_SWAP_OBJS) $(CHECKER_OBJS) $(PUSH_SWAP_HEADER)\
			$(PRINTF_LIB) $(OPERATIONS_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP_OBJS) $(OPERATIONS_OBJS) $(PRINTF_LIB) \
	-o $(NAME) -I. -Ift_printf
	@$(CC) $(CFLAGS) $(OBJS) $(CHECKER_OBJS) $(OPERATIONS_OBJS) $(PRINTF_LIB) \
	-o $(CHECKER_NAME) -I. -Ift_printf

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@  $< -I. -Ift_printf

clean:
	@rm -rf $(OBJS)
	@rm -rf $(PUSH_SWAP_OBJS)
	@rm -rf $(CHECKER_OBJS)
	@rm -rf $(LIBFT)
	@$(MAKE) -C $(PRINTF) clean

push_swap_clean:
	@rm -rf $(OBJS)
	@rm -rf $(PUSH_SWAP_OBJS)
	@rm -rf $(CHECKER_OBJS)
	@rm -rf $(LIBFT)

fclean: push_swap_clean
	@rm -f $(NAME)
	@rm -f $(CHECKER_NAME)
	@$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re