# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 19:42:50 by hkono             #+#    #+#              #
#    Updated: 2021/12/20 21:11:53 by hkono            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
	update_format_info.c \
	print_format.c \
	format_char.c \
	format_string.c \
	format_address.c \
	format_integer.c \
	format_unsigned.c \
	format_hexa.c \
	format_percent.c \
	is_minus_print.c \
	is_minus_print_int.c \
	not_minus_print.c \
	not_minus_print_int.c \
	hexa_converter.c \
	ft_printf_utils.c \
	ft_utoa.c
OBJS = $(addprefix src/, $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = -L./libft -lft
INCLUDES = -I ./includes
vpath %.c src

$(NAME): $(OBJS)
	$(MAKE) bonus -C libft
	cp libft/libft.a ./libftprintf.a
	ar rc $@ $(OBJS)
	ranlib $@

%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJS)

fclean:
	$(MAKE) fclean -C libft
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all

.PHONEY = all clean fclean re
