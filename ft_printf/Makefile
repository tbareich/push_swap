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
LIBFT = libft/obj/*.o
LIBFT_LIB = libft/libft.a

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

all: sub-make $(NAME)

sub-make:
	@$(MAKE) -C libft

$(NAME): $(OBJS) $(SPECIFIERS) $(PARSERS) $(HELPERS) $(FT_PRINTF_HEADER) $(LIBFT_LIB)
	@ar rc $(NAME) $(OBJS) $(SPECIFIERS) $(LIBFT) $(PARSERS) $(HELPERS)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< -I. -Ilibft

clean:
	@rm -rf $(OBJS)
	@rm -rf $(SPECIFIERS)
	@rm -rf $(PARSERS)
	@rm -rf $(HELPERS)
	@$(MAKE) clean -C libft

printf_clean: 
	@rm -rf $(OBJS)
	@rm -rf $(SPECIFIERS)
	@rm -rf $(PARSERS)
	@rm -rf $(HELPERS)

fclean: printf_clean 
	@rm -f $(NAME)
	@$(MAKE) fclean -C libft

re: fclean all
