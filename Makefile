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

PS_NAME = push_swap
C_NAME = checker
PUSH_SWAP_HEADER = push_swap.h
OBJS = src/check_args.o src/merge_sort.o src/is_sorted.o src/run_action.o

PUSH_SWAP_OBJS = push_swap.o src/push_swap/sort_by_chanks.o\
				src/push_swap/search_in_range.o src/push_swap/move_to_top.o\
				src/push_swap/is_min_max.o src/push_swap/simple_sort.o\
				src/push_swap/add_action.o

CHECKER_OBJS = checker.o src/checker/reader.o src/checker/check_opt.o
OPERATIONS_OBJS = src/operations/sx.o src/operations/px.o\
				src/operations/rx.o src/operations/r_a_b.o src/operations/rrx.o\
				src/operations/rr_a_b.o src/operations/s_a_b.o
PRINTF = ft_printf
PRINTF_LIB =  ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: sub-make $(PS_NAME) $(C_NAME)

sub-make:
	@$(MAKE) -C $(PRINTF)

$(PS_NAME): $(OBJS) $(PUSH_SWAP_OBJS) $(PUSH_SWAP_HEADER)\
			$(PRINTF_LIB) $(OPERATIONS_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(PUSH_SWAP_OBJS) $(OPERATIONS_OBJS) $(PRINTF_LIB) \
	-o $(PS_NAME) -I. -Ift_printf

$(C_NAME): $(OBJS) $(CHECKER_OBJS) $(PUSH_SWAP_HEADER)\
			$(PRINTF_LIB) $(OPERATIONS_OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(CHECKER_OBJS) $(OPERATIONS_OBJS) $(PRINTF_LIB) \
	-o $(C_NAME) -I. -Ift_printf

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@  $< -I. -Ift_printf
	@echo "$(GREEN).$(RESET)\c"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(PUSH_SWAP_OBJS)
	@rm -rf $(CHECKER_OBJS)
	@rm -rf $(OPERATIONS_OBJS)
	@rm -rf $(LIBFT)
	@$(MAKE) -C $(PRINTF) clean

push_swap_clean:
	@rm -rf $(OBJS)
	@rm -rf $(PUSH_SWAP_OBJS)
	@rm -rf $(CHECKER_OBJS)
	@rm -rf $(OPERATIONS_OBJS)
	@rm -rf $(LIBFT)

fclean: push_swap_clean
	@rm -f $(PS_NAME)
	@rm -f $(C_NAME)
	@$(MAKE) -C $(PRINTF) fclean

re: fclean all

.PHONY: all clean fclean re