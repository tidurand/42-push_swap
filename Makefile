# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 10:14:27 by tidurand          #+#    #+#              #
#    Updated: 2022/01/11 13:11:19 by tidurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	actions.c \
		check_errors.c \
		cut_after_demi.c \
		cut_before_demi.c \
		moves.c \
		push_b.c \
		push_swap.c \
		push_swap_3.c \
		push_swap_5.c \
		push_swap_small.c \
		push_swap_utils.c \
		sort.c \
		utils_2.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

$(NAME):	$(OBJS)
		gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean $(NAME)
