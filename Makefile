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

NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
CC = cc
RM = rm -f
LIBS = libs/libft/libft.a

OBJS = $(SRCS:.c=.o)
SRCS = srcs/main.c srcs/stack_checker.c srcs/stack_maker.c srcs/stack_moves.c
all: $(NAME)

deps:
	$(MAKE) -C ./libs/libft/

$(NAME): deps $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libs/libft/

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libs/libft/
	$(RM) gdb
gdb: deps
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o gdb -g
re: fclean all
