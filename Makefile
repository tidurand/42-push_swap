# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tidurand <tidurand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/12 10:14:27 by tidurand          #+#    #+#              #
#    Updated: 2022/01/09 08:57:02 by tidurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	*.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra

NAME = push_swap

all: $(NAME)

$(NAME):	$(OBJS)
		gcc $(FLAGS) $(SRCS) -o $(NAME) -g3 -fsanitize=address

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re