# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 10:54:52 by hkono             #+#    #+#              #
#    Updated: 2021/11/23 16:07:53 by hkono            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libsrc.a

OBJS = ft_printf.o \
	update_format_info.o \
	print_format.o \
	format_char.o \
	format_string.o \
	format_address.o \
	format_integer.o \
	format_unsigned.o \
	format_hexa.o \
	format_percent.o \
	is_minus_print.o \
	is_minus_print_int.o \
	not_minus_print.o \
	not_minus_print_int.o \
	hexa_converter.o \
	ft_printf_utils.o \
	ft_utoa.o

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I../includes
LIBS = -L../libft

$(NAME): $(OBJS)
	$(AR) -rcs $(NAME) $^

.SUFFIXES: .c .o

.c.o:
	$(CC) $(CFLAGS) -c $< $(INCLUDES)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
