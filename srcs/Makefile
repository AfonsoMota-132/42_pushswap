# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 11:41:17 by afogonca          #+#    #+#              #
#    Updated: 2024/11/23 11:46:23 by afogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE		= make -C

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
LIBS = libs/libft/libft.a

OBJS = $(SRCS:.c=.o)
SRCS = srcs/main.c srcs/stack_checker.c srcs/stack_maker.c srcs/stack_maker2.c \
	   srcs/radix.c srcs/stack_moves_a.c srcs/stack_moves_b.c \
	   srcs/ft_free.c srcs/initial.c srcs/stack_checker2.c

all: deps $(NAME)

deps:
	$(MAKE) ./libs/libft/

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C ./libs/libft/

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libs/libft/
	$(RM) gdb
	rm -fr push_swap_visualizer

gdb: deps
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o gdb -g

re: fclean all

visualizer:
	git clone https://github.com/o-reo/push_swap_visualizer.git && \
	cd push_swap_visualizer && \
	mkdir build && \
	cd build && \
	cmake .. && \
	make && \
	./bin/visualizer
