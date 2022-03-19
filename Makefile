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
VISUALIZATOR_HEADER = visualizator/visualisator.h

VISUALIZATOR_OBJS = visualizator/visualisator.o

OBJS = src/check_args.o src/merge_sort.o src/is_sorted.o src/run_action.o

PUSH_SWAP_OBJS = push_swap.o\
				src/push_swap/search_in_range.o src/push_swap/move_to_top.o\
				src/push_swap/simple_sort.o\
				src/push_swap/push_b.o src/push_swap/push_a.o \
				src/push_swap/find_element_position.o\
				src/push_swap/is_min_max.o\
				src/push_swap/is_sorted_dir.o\
				src/push_swap/ajust_stack.o

CHECKER_OBJS = checker.o src/checker/reader.o src/checker/check_opt.o
OPERATIONS_OBJS = src/operations/sx.o src/operations/px.o\
				src/operations/rx.o src/operations/r_a_b.o src/operations/rrx.o\
				src/operations/rr_a_b.o src/operations/s_a_b.o
LIBFT = libft
LIBFT_LIB =  libft/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
SDL_INCLUDE    = -I/Users/$$USER/brew/Cellar/sdl2/2.0.20/include \
        -I/Users/$$USER/brew/Cellar/sdl2_ttf/2.0.18_1/include

SDL_LIBS = -L /Users/$$USER/brew/Cellar/sdl2/2.0.20/lib \
        -L /Users/$$USER/brew/Cellar/sdl2_ttf/2.0.18_1/lib

SDL_FLAGGS= `sdl2-config --cflags --libs` -lSDL2 -lSDL2_ttf
# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: subsystem $(PS_NAME) $(C_NAME)

subsystem:
	@$(MAKE) -C $(LIBFT)

$(PS_NAME): $(OBJS) $(PUSH_SWAP_OBJS) $(VISUALIZATOR_OBJS) \
	$(OPERATIONS_OBJS) $(VISUALIZATOR_HEADER) $(PUSH_SWAP_HEADER) 
	$(CC) $(CFLAGS) $(SDL_FLAGGS) $(SDL_INCLUDE) $(SDL_LIBS) $(OBJS) \
	$(PUSH_SWAP_OBJS) $(OPERATIONS_OBJS) $(VISUALIZATOR_OBJS) $(LIBFT_LIB) \
	-o $(PS_NAME) -I.

$(C_NAME): $(OBJS) $(CHECKER_OBJS) $(PUSH_SWAP_HEADER) \
	$(VISUALIZATOR_OBJS) $(VISUALIZATOR_HEADER) $(OPERATIONS_OBJS) 
	$(CC) $(CFLAGS) $(SDL_FLAGGS) $(SDL_INCLUDE) $(SDL_LIBS) $(OBJS) \
	$(VISUALIZATOR_OBJS) $(CHECKER_OBJS) $(OPERATIONS_OBJS) $(LIBFT_LIB) \
	-o $(C_NAME) -I.

%.o: %.c $(VISUALIZATOR_HEADER) $(PUSH_SWAP_HEADER) 
	$(CC) $(CFLAGS) $(SDL_INCLUDE) -c -o $@  $< -I. -Ivisualizator -I$(LIBFT)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(PUSH_SWAP_OBJS)
	@rm -rf $(CHECKER_OBJS)
	@rm -rf $(OPERATIONS_OBJS)
	@rm -rf $(VISUALIZATOR_OBJS)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(PS_NAME)
	@rm -f $(C_NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean subsystem all

.PHONY: all clean fclean re subsystem