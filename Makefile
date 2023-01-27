# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabboune <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/25 15:59:07 by nabboune          #+#    #+#              #
#    Updated: 2023/01/26 23:02:13 by nabboune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS =	help_functions_0.c \
		help_functions_1.c \
		push_swap.c \
		Stack_operations/helpers_0.c \
		Stack_operations/helpers_1.c \
		Stack_operations/helpers_2.c \
		Stack_operations/push_no_print.c \
		Stack_operations/reverse_rotate_no_print.c \
		Stack_operations/rotate_no_print.c \
		Stack_operations/swap_no_print.c \
		Utils/printers.c \
		Utils/push.c \
		Utils/reverse_rotate.c \
		Utils/rotate.c \
		Utils/swap.c \
		Sorting/algo.c \
		Sorting/push_back.c \
		Sorting/Sort_Array.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS)

$(LIBFT) :
	cd Libft/ && $(MAKE)

all : $(NAME)

clean :
	cd Libft && $(MAKE) clean && cd .. && $(RM) $(OBJS) && $(RM) libft.a

fclean : clean
	cd Libft && $(MAKE) fclean && cd .. && $(RM) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re
