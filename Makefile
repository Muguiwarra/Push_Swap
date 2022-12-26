# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabboune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 15:59:07 by nabboune          #+#    #+#              #
#    Updated: 2022/12/25 23:00:34 by nabboune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_stack_operations.c \
		push_swap.c

OBJS = $(SRCS:.c=.o)


$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(LIBFT) $(OBJS)

$(LIBFT) :
	cd Libft/ && $(MAKE)

all : $(NAME)

clean :
	cd Libft && $(MAKE) clean && cd .. && $(RM) $(OBJS)

fclean : clean
	cd Libft && $(MAKE) fclean && cd .. && $(RM) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
