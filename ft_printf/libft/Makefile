# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 14:13:12 by tbareich          #+#    #+#              #
#    Updated: 2022/02/09 09:51:59 by tbareich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
LIBFT_HEADER = libft.h
OBJS_DIR= obj/
SRCS_DIR= src/
SRCS_NO_PATH= bst_delete.c bst_deletenode.c bst_find.c \
		bst_inorder.c bst_insert.c bst_max.c \
		bst_min.c bst_modify_addr.c bst_newnode.c \
		ft_atoi.c ft_bzero.c ft_delcontent.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_lstadd.c ft_lstaddat.c ft_lstdel.c \
		ft_lstdelat.c ft_lstdelone.c ft_lstiter.c \
		ft_lstlen.c ft_lstmap.c ft_lstnew.c \
		ft_lstpop.c ft_lstpush.c ft_lstshift.c \
		ft_memalloc.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memdel.c \
		ft_memmove.c ft_memset.c ft_putchar.c \
		ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putlst.c ft_putnbr.c ft_putnbr_fd.c \
		ft_putstr.c ft_putstr_fd.c ft_realloc.c \
		ft_strcat.c ft_strchr.c ft_strclr.c \
		ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strdup_free.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strjoin_free.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strncat.c \
		ft_strncmp.c ft_strncpy.c ft_strnequ.c \
		ft_strnew.c ft_strnstr.c ft_strrchr.c \
		ft_strsplit.c ft_strstr.c ft_strsub.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c \
		get_int_len.c get_next_line.c ft_swap.c\
		ft_abs.c is_int.c\
		stack.c error.c min.c max.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_NO_PATH))
OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)


$(NAME): $(OBJS) $(LIBFT_HEADER)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c -o $@ $< -I. -Ilibft

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
