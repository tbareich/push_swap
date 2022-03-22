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

define HEADER
                         █████                                                
                        ░░███                                                 
 ████████ █████ █████████░███████          ██████████ ███ ██████████ ████████ 
░░███░░██░░███ ░██████░░ ░███░░███        ███░░░░███ ░███░░██░░░░░██░░███░░███
 ░███ ░███░███ ░██░░█████░███ ░███       ░░█████░███ ░███ ░██████████░███ ░███
 ░███ ░███░███ ░███░░░░██░███ ░███        ░░░░██░░██████████████░░███░███ ░███
 ░███████ ░░█████████████████ ██████████████████ ░░████░████░░███████░███████ 
 ░███░░░   ░░░░░░░░░░░░░░░░░ ░░░░░░░░░░░░░░░░░░   ░░░░ ░░░░  ░░░░░░░░░███░░░  
 ░███                                                                ░███     
 █████                                                               █████    
░░░░░                                                               ░░░░░     
endef
export HEADER
AUTHOR				:= Tareq Bareich

################################## Variables ###################################

PUSH_SWAP_NAME		:= push_swap
CHECKER_NAME		:= checker
CC					:= gcc
CFLAGS				:= -Wall -Werror -Wextra
SDL_FLAGGS			:= `sdl2-config --cflags --libs` -lSDL2 -lSDL2_ttf
PUSH_SWAP_HEADER	:= includes/push_swap.h
VISUALISER_HEADER 	:= includes/visualiser.h
BONUS_FOLDER 		:= bonus
LIBFT 				:= libft
INCLUDES 			:= includes/
LIBFT_INCLUDES 		:= $(LIBFT)/includes/
LIBFT_LIB 			:= libft/libft.a
SDL_INCLUDES 		:= -I/Users/$$USER/brew/Cellar/sdl2/2.0.20/include \
   					-I/Users/$$USER/brew/Cellar/sdl2_ttf/2.0.18_1/include
SDL_LIBS 			:= -L /Users/$$USER/brew/Cellar/sdl2/2.0.20/lib \
    				-L /Users/$$USER/brew/Cellar/sdl2_ttf/2.0.18_1/lib

#################################### Colors ####################################

GREEN				:= \033[1;32m
RED					:= \033[1;31m
BLUE				:= \033[1;34m
WHITE				:= \033[1;37m
LIGHTYELLOW			:= \033[1;33m
RESET				:= \033[0m

################################ Preprocessing #################################

BONUS_SRCS			:= visualiser.c draw.c options.c 
BONUS_OBJS			:= $(addprefix obj/bonus/, $(BONUS_SRCS:.c=.o))

SHARED_SRCS			:= check_args.c merge_sort.c is_sorted.c run_action.c \
					error.c free_data.c
SHARED_OBJS			:= $(addprefix obj/shared/, $(SHARED_SRCS:.c=.o))

PUSH_SWAP_SRCS		:= move_to_top.c simple_sort.c push_b.c push_a.c \
					find_element_position.c is_min_max.c is_sorted_dir.c \
					sort_b.c sort_a.c push_swap.c
PUSH_SWAP_OBJS		:= $(addprefix obj/push_swap/, $(PUSH_SWAP_SRCS:.c=.o))

CHECKER_SRCS		:=  reader.c check_opt.c checker.c
CHECKER_OBJS		:= $(addprefix obj/checker/, $(CHECKER_SRCS:.c=.o))

OPERATIONS_SRCS		:= sx.c px.c rx.c r_a_b.c rrx.c rr_a_b.c s_a_b.c
OPERATIONS_OBJS		:= $(addprefix obj/operations/, $(OPERATIONS_SRCS:.c=.o))

#################################### Rules #####################################

all: print_header $(LIBFT) $(PUSH_SWAP_NAME) $(CHECKER_NAME)

print_header:
	@clear
	@echo "$(GREEN)$$HEADER$(RESET)"
	@echo "    \t\t\t$(WHITE)By: $(GREEN)$(AUTHOR) $(RESET)\n\n\n\n"
	@echo "$(WHITE)Start building objects$(RESET)"

$(LIBFT_LIB): print_header
	@$(MAKE) -C $(LIBFT)

$(PUSH_SWAP_NAME): $(LIBFT_LIB) $(SHARED_OBJS) $(OPERATIONS_OBJS) \
	$(PUSH_SWAP_OBJS) $(BONUS_OBJS) $(VISUALISER_HEADER) $(PUSH_SWAP_HEADER)
	@$(CC) $(CFLAGS) $(SDL_FLAGGS) $(SDL_INCLUDES) $(SDL_LIBS) $(SHARED_OBJS) \
	$(OPERATIONS_OBJS) $(BONUS_OBJS) $(PUSH_SWAP_OBJS) $(LIBFT_LIB) \
	-o $(PUSH_SWAP_NAME) -I$(INCLUDES)
	@echo "$(WHITE)\npush_swap: $(BLUE)linked$(RESET)"

$(CHECKER_NAME): $(LIBFT_LIB) $(SHARED_OBJS) $(OPERATIONS_OBJS) \
	$(CHECKER_OBJS) $(PUSH_SWAP_HEADER) $(BONUS_OBJS) $(VISUALISER_HEADER)
	@$(CC) $(CFLAGS) $(SDL_FLAGGS) $(SDL_INCLUDES) $(SDL_LIBS) $(SHARED_OBJS) \
	$(BONUS_OBJS)  $(OPERATIONS_OBJS) $(CHECKER_OBJS) $(LIBFT_LIB) \
	-o $(CHECKER_NAME) -I$(INCLUDES)
	@echo "$(WHITE)\nchecker: $(BLUE)linked$(RESET)"

obj/operations/%.o: src/operations/%.c $(VISUALISER_HEADER) $(PUSH_SWAP_HEADER)
	@mkdir -p  $(dir $@)
	@$(CC) $(CFLAGS) $(SDL_INCLUDES) -c -o $@  $< -I$(INCLUDES) \
	-I$(LIBFT_INCLUDES)
	@echo "$(GREEN).\c$(RESET)"

obj/push_swap/%.o: src/push_swap/%.c $(VISUALISER_HEADER) $(PUSH_SWAP_HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(SDL_INCLUDES) -c -o $@  $< -I$(INCLUDES) \
	-I$(LIBFT_INCLUDES)
	@echo "$(GREEN).\c$(RESET)"

obj/checker/%.o: src/checker/%.c $(VISUALISER_HEADER) $(PUSH_SWAP_HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(SDL_INCLUDES) -c -o $@  $< -I$(INCLUDES) \
	-I$(LIBFT_INCLUDES)
	@echo "$(GREEN).\c$(RESET)"


obj/shared/%.o: src/shared/%.c $(VISUALISER_HEADER) $(PUSH_SWAP_HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(SDL_INCLUDES) -c -o $@  $< -I$(INCLUDES) \
	-I$(LIBFT_INCLUDES)
	@echo "$(GREEN).\c$(RESET)"

obj/bonus/%.o: src/bonus/%.c $(VISUALISER_HEADER) $(PUSH_SWAP_HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(SDL_INCLUDES) -c -o $@  $< -I$(INCLUDES) \
	-I$(LIBFT_INCLUDES)
	@echo "$(GREEN).\c$(RESET)"

clean:
	@rm -rf obj
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@rm -f $(PUSH_SWAP_NAME)
	@rm -f $(CHECKER_NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re print_header