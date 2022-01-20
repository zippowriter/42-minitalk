# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 09:47:44 by hkono             #+#    #+#              #
#    Updated: 2022/01/10 18:52:10 by hkono            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME = server
CLIENT_NAME = client

SERVER_SRCS = main_server.c \
	recieve_signal.c \
	utils_error.c \
	buf_size.c
SERVER_OBJS = $(addprefix srcs/, $(SERVER_SRCS:.c=.o))
CLIENT_SRCS = main_client.c \
	utils_error.c
CLIENT_OBJS = $(addprefix srcs/, $(CLIENT_SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./ft_printf/includes
LIBS = -L./ft_printf -lftprintf
vpath %.c srcs

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(CLIENT_OBJS) $(SERVER_OBJS)
	$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIBS) -o $(CLIENT_NAME)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBS) -o $(SERVER_NAME)

clean:
	$(MAKE) clean -C ft_printf
	$(RM) $(SERVER_OBJS)
	$(RM) $(CLIENT_OBJS)

fclean: clean
	$(MAKE) fclean -C ft_printf
	$(RM) $(SERVER_NAME)
	$(RM) $(CLIENT_NAME)

re: fclean all
