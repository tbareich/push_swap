# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbareich <tbareich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/24 14:13:12 by tbareich          #+#    #+#              #
#    Updated: 2019/10/31 20:12:55 by mesafi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FT_PRINTF_HEADER = ft_printf.h
OBJS = ft_printf.o
LIBFT = libft/bst_delete.o libft/bst_deletenode.o libft/bst_find.o \
		libft/bst_inorder.o libft/bst_insert.o libft/bst_max.o \
		libft/bst_min.o libft/bst_modify_addr.o libft/bst_newnode.o \
		libft/ft_atoi.o libft/ft_bzero.o libft/ft_delcontent.o \
		libft/ft_isalnum.o libft/ft_isalpha.o libft/ft_isascii.o \
		libft/ft_isdigit.o libft/ft_isprint.o libft/ft_itoa.o \
		libft/ft_lstadd.o libft/ft_lstaddat.o libft/ft_lstdel.o \
		libft/ft_lstdelat.o libft/ft_lstdelone.o libft/ft_lstiter.o \
		libft/ft_lstlen.o libft/ft_lstmap.o libft/ft_lstnew.o \
		libft/ft_lstpop.o libft/ft_lstpush.o libft/ft_lstshift.o \
		libft/ft_memalloc.o libft/ft_memccpy.o libft/ft_memchr.o \
		libft/ft_memcmp.o libft/ft_memcpy.o libft/ft_memdel.o \
		libft/ft_memmove.o libft/ft_memset.o libft/ft_putchar.o \
		libft/ft_putchar_fd.o libft/ft_putendl.o libft/ft_putendl_fd.o \
		libft/ft_putlst.o libft/ft_putnbr.o libft/ft_putnbr_fd.o \
		libft/ft_putstr.o libft/ft_putstr_fd.o libft/ft_realloc.o \
		libft/ft_strcat.o libft/ft_strchr.o libft/ft_strclr.o \
		libft/ft_strcmp.o libft/ft_strcpy.o libft/ft_strdel.o \
		libft/ft_strdup.o libft/ft_strdup_free.o libft/ft_strequ.o \
		libft/ft_striter.o libft/ft_striteri.o libft/ft_strjoin.o \
		libft/ft_strjoin_free.o libft/ft_strlcat.o libft/ft_strlen.o \
		libft/ft_strmap.o libft/ft_strmapi.o libft/ft_strncat.o \
		libft/ft_strncmp.o libft/ft_strncpy.o libft/ft_strnequ.o \
		libft/ft_strnew.o libft/ft_strnstr.o libft/ft_strrchr.o \
		libft/ft_strsplit.o libft/ft_strstr.o libft/ft_strsub.o \
		libft/ft_strtrim.o libft/ft_tolower.o libft/ft_toupper.o \
		libft/get_int_len.o libft/get_next_line.o 

SPECIFIERS = specifiers/ft_specifier_char.o specifiers/ft_specifier_double.o \
		specifiers/ft_specifier_hex.o specifiers/ft_specifier_int.o \
		specifiers/ft_specifier_octal.o specifiers/ft_specifier_pointer.o \
		specifiers/ft_specifier_string.o specifiers/ft_specifier_binary.o \
		specifiers/ft_specifier_uint.o

PARSERS = parsers/ft_parse_flags.o parsers/ft_parse_format.o \
		parsers/ft_parse_length.o parsers/ft_parse_parameter.o \
		parsers/ft_parse_precision.o parsers/ft_parse_specifier.o \
		parsers/ft_parse_width.o 
			
HELPERS = helpers/ft_snumtoa.o helpers/ft_unumtoa.o helpers/pad_spaces.o \
		helpers/pad_zeros.o helpers/ft_percent.o helpers/ft_multiplication.o \
		helpers/ft_fast_power.o helpers/ft_addition.o helpers/ft_round.o \
		helpers/print_double.o helpers/ft_fraction.o helpers/ft_whole.o \
		helpers/omit_zero.o helpers/is_flag.o helpers/error_handler.o \
		helpers/separated_number.o

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(SPECIFIERS) $(LIBFT) $(PARSERS) $(HELPERS) $(FT_PRINTF_HEADER)
	@ar rc $(NAME) $(OBJS) $(SPECIFIERS) $(LIBFT) $(PARSERS) $(HELPERS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(SPECIFIERS)
	@rm -rf $(PARSERS)
	@rm -rf $(HELPERS)
	@rm -rf $(LIBFT)

fclean: clean
	@rm -f $(NAME)

re: fclean all
